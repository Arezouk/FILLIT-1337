/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:50:23 by arezouk           #+#    #+#             */
/*   Updated: 2018/10/09 21:15:36 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*ch;
	char	*str;
	size_t	i;

	ch = malloc(size);
	str = ch;
	i = 0;
	if (ch != NULL)
	{
		while (i < size)
		{
			str[i] = 0;
			i++;
		}
		return (ch);
	}
	return (0);
}
