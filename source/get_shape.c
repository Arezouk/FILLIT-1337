/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:29:19 by arezouk           #+#    #+#             */
/*   Updated: 2018/11/26 04:38:14 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		coordinate(char *ch, t_point *min, t_point *max)
{
	int		i;

	i = 0;
	while (i <= 19)
	{
		if (ch[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_tetri		*get_shape(char *ch, char alpha)
{
	int		i;
	char	**posi;
	t_point	*min;
	t_point	*max;
	t_tetri	*tetri;

	i = 0;
	max = tetri_coord(0, 0);
	min = tetri_coord(3, 3);
	coordinate(ch, min, max);
	posi = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	while (i < max->y - min->y + 1)
	{
		posi[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(posi[i], ch + (min->x) + (i + min->y) * 5,
				max->x - min->x + 1);
		i++;
	}
	tetri = tetri_struct(posi, max->x - min->x + 1, max->y - min->y + 1,
				alpha);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetri);
}
