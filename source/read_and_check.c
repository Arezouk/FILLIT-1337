/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:49:46 by arezouk           #+#    #+#             */
/*   Updated: 2018/12/01 18:59:43 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_tetri(char *ch)
{
	int		conec;
	int		i;

	i = 0;
	conec = 0;
	while (i < 20)
	{
		if (ch[i] == '#')
		{
			if ((i + 1) < 20 && ch[i + 1] == '#')
				conec++;
			if ((i - 1) >= 0 && ch[i - 1] == '#')
				conec++;
			if ((i + 5) < 20 && ch[i + 5] == '#')
				conec++;
			if ((i - 5) >= 0 && ch[i - 5] == '#')
				conec++;
		}
		i++;
	}
	return (conec == 8 || conec == 6);
}

int			check_block(char *ch, int block)
{
	int		i;
	int		slot;

	i = 0;
	slot = 0;
	while (++i <= 19)
	{
		if (i % 5 < 4)
		{
			if (!(ch[i] == '#' || ch[i] == '.'))
				return (0);
			if (ch[i] == '#' && ++slot > 4)
				return (0);
		}
		else
		{
			if (ch[i] != '\n')
				return (0);
		}
	}
	if (block == 21 && ch[20] != '\n')
		return (0);
	if (!check_tetri(ch))
		return (0);
	return (1);
}

t_list		*read_tetri(int fd)
{
	char	*ch;
	int		block[2];
	t_list	*list;
	t_tetri	*tetri;
	char	alpha;

	ch = ft_strnew(21);
	list = NULL;
	alpha = 'A';
	while ((block[1] = read(fd, ch, 21)) >= 20)
	{
		if (check_block(ch, block[1]) != 1 ||
				(tetri = get_shape(ch, alpha++)) == NULL)
			return (free_list(list));
		ft_lstadd(&list, ft_lstnew(tetri, sizeof(t_tetri)));
		ft_memdel((void **)&tetri);
		block[0] = block[1];
	}
	ft_memdel((void **)&ch);
	if (block[1] != 0 || block[0] == 21)
		return (free_list(list));
	list_reverse(&list);
	return (list);
}
