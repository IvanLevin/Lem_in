/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:25:29 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/02 16:25:30 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

static	void	part1_bfs(t_lem *lem, t_int **turn)
{
	int		item;
	t_int	*line;

	item = shift_int(turn);
	line = lem->node[item].line;
	while (line)
	{
		if (lem->node[line->integer].id == 2147483647 && \
			line->integer && line->integer != lem->rooms - 1)
		{
			if (lem->node[line->integer].id > lem->node[item].id + 1
				|| lem->node[line->integer].id == 2147483647)
				lem->node[line->integer].id = lem->node[item].id + 1;
			push_int(turn, create_int(line->integer));
		}
		line = line->next;
	}
}

void			part1(t_lem *lem)
{
	t_int	*turn;

	turn = create_int(lem->rooms - 1);
	lem->node[lem->rooms - 1].id = 0;
	while (turn)
	{
		part1_bfs(lem, &turn);
	}
}
