/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:35:35 by arezouk           #+#    #+#             */
/*   Updated: 2018/12/01 00:37:42 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*tetri_coord(int x, int y)
{
	t_point	*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

t_tetri		*tetri_struct(char **posi, int width, int height, char alpha)
{
	t_tetri	*tetri;

	tetri = ft_memalloc(sizeof(t_tetri));
	tetri->posi = posi;
	tetri->width = width;
	tetri->height = height;
	tetri->alpha = alpha;
	return (tetri);
}

void		free_tetri_struct(t_tetri *tetri)
{
	int		i;

	i = 0;
	while (i < tetri->height)
	{
		ft_memdel((void **)&(tetri->posi[i]));
		i++;
	}
	ft_memdel((void **)&(tetri->posi));
	ft_memdel((void **)&tetri);
}

t_list		*free_list(t_list *list)
{
	t_tetri	*tetri;
	t_list	*next;

	while (list)
	{
		tetri = (t_tetri *)list->content;
		next = list->next;
		free_tetri_struct(tetri);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}
