/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:25:34 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/03 15:37:42 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lem_in.h"

static	int		get_mini_id(t_lem *lem, t_int *line, t_stream *stream)
{
	int		id;
	int		room;

	id = 2147483647;
	room = -3;
	while (line)
	{
		if (!stream->used[line->integer] && id > lem->node[line->integer].id)
		{
			id = lem->node[line->integer].id;
			room = line->integer;
		}
		line = line->next;
	}
	return (room);
}

void			part2(t_lem *lem, t_stream *stream)
{
	int		room;
	int		turn;

	if (stream->turn)
	{
		turn = shift_int(&stream->turn);
		room = get_mini_id(lem, lem->node[turn].line, stream);
		if (room == -3 || turn >= lem->rooms)
			return ;
		if (lem->node[turn].id > lem->node[room].id && (!stream->used[room]
			|| room == lem->rooms - 1))
		{
			stream->used[turn] = room;
			if (room != lem->rooms - 1)
				push_int(&stream->turn, create_int(room));
			if (room != lem->rooms - 1)
				part2(lem, stream);
		}
	}
}
