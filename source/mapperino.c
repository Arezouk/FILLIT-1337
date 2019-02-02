/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapperino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:53:08 by arezouk           #+#    #+#             */
/*   Updated: 2018/11/30 23:30:12 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*create_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->tab = (char **)ft_memalloc(sizeof(char *) * size);
	while (i < size)
	{
		map->tab[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void		free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->tab[i]));
		i++;
	}
	ft_memdel((void **)&(map->tab));
	ft_memdel((void **)&map);
}

void		mapperino(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		write(1, map->tab[i], map->size);
		ft_putchar('\n');
		i++;
	}
}

void		place_tetri(t_tetri *tetri, t_map *map, t_point *point, char alpha)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->posi[j][i] == '#')
				map->tab[point->y + j][point->x + i] = alpha;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}

int			check_and_place(t_tetri *tetri, t_map *map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->posi[j][i] == '#' && map->tab[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	place_tetri(tetri, map, tetri_coord(x, y), tetri->alpha);
	return (1);
}
