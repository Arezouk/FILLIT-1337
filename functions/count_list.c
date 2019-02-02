/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:37:35 by arezouk           #+#    #+#             */
/*   Updated: 2018/11/26 04:49:15 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		count_list(t_list *list)
{
	size_t	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
