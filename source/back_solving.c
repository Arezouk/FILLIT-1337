/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_solving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:25:06 by arezouk           #+#    #+#             */
/*   Updated: 2018/11/26 04:44:13 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			small_sqrt(int i)
{
	int	size;

	size = 2;
	while (size * size < i)
	{
		size++;
	}
	return (size);
}

int			back_solving(t_map *map, t_list *list)
{
	int		x;
	int		y;
	t_tetri	*tetri;

	if (list == NULL)
		return (1);
	y = 0;
	tetri = (t_tetri *)(list->content);
	while (y < map->size - tetri->height + 1)
	{
		x = 0;
		while (x < map->size - tetri->width + 1)
		{
			if (check_and_place(tetri, map, x, y))
			{
				if (back_solving(map, list->next))
					return (1);
				else
					place_tetri(tetri, map, tetri_coord(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map		*solve(t_list *list)
{
	t_map	*map;
	int		size;

	size = small_sqrt(count_list(list) * 4);
	map = create_map(size);
	while (!back_solving(map, list))
	{
		size++;
		free_map(map);
		map = create_map(size);
	}
	return (map);
}
