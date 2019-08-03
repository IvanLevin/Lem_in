/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:24:53 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/03 15:39:32 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/lem_in.h"

void		clear_graf(t_graf **graf)
{
	free((*graf)->start);
	(*graf)->start = NULL;
	free((*graf)->end);
	(*graf)->end = NULL;
	clear_link(&(*graf)->link);
	clear_rooms(&(*graf)->rooms);
	free(*graf);
	*graf = NULL;
}

void		clear_one_int(t_int **integer)
{
	(void)(*integer)->integer;
	(*integer)->next = NULL;
	free(*integer);
	(*integer) = NULL;
}

void		clear_int(t_int **integer)
{
	t_int *next;

	while (*integer)
	{
		next = (*integer)->next;
		clear_one_int(integer);
		*integer = next;
	}
}

void		clear_row(t_node **node, int rooms)
{
	int		n;

	n = 0;
	while (n < rooms)
	{
		(void)(*node)[n].id;
		(*node)[n].name = NULL;
		if ((*node)[n].line)
			clear_int(&(*node)[n].line);
		n++;
	}
	free(*node);
	*node = NULL;
}
