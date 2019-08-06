/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_conntecting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:25:53 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/02 16:25:54 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

static t_int	*del_connect(t_int *line, int y)
{
	t_int	**old;
	t_int	*item;

	old = &line;
	while ((*old)->next)
	{
		printf("\n  y = %d\n", y);
		printf("(*old)->next->integer = %d\n", (*old)->next->integer);
		if ((*old)->next->integer == y)
		{
			item = (*old)->next->next;
			free((*old)->next);
			(*old)->next = item;
			return (line);
		}
		old = &(*old)->next;
	}
	return (line);
}

static void		del_connects(t_lem *lem, int x, int y)
{
	lem->node[x].line = del_connect(lem->node[x].line, y);
	lem->node[y].line = del_connect(lem->node[y].line, x);
}

void			del_connecting(t_lem *lem, int *used)
{
	int		n;
	int		item;
	t_int	*line;

	n = 0;
	while (n != lem->rooms - 1)
	{
		if (used[n] != 0 && (used[n] != (lem->rooms - 1)))
		{
			line = lem->node[used[n]].line;
			while (line)
			{
				item = line->integer;
				line = line->next;
				del_connects(lem, used[n], item);
			}
		}
		n = used[n];
		if (!n)
			return ;
	}
}
