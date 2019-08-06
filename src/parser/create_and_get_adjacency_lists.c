/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_get_adjacency_lists.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:38:04 by breolson          #+#    #+#             */
/*   Updated: 2019/08/03 16:40:48 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int				add_node_in_node(t_int **link, t_int *data)
{
	t_int	*next;

	if (!data)
		return (1);
	next = *link;
	if (next)
	{
		data->next = *link;
		*link = data;
	}
	else
		*link = data;
	return (0);
}

int				find_position(t_rooms *rooms, char *name_room, int count)
{
	while (rooms)
	{
		count--;
		if (!ft_strcmp(name_room, rooms->name))
			return (count);
		rooms = rooms->next;
	}
	return (0);
}

void			get_nodes(t_graf *graf, t_lem *lem)
{
	t_link	*link;
	int		x;
	int		y;

	link = graf->link;
	while (link)
	{
		x = find_position(graf->rooms, (link->name)[0], lem->rooms);
		y = find_position(graf->rooms, (link->name)[1], lem->rooms);
		add_node_in_node(&((lem->node)[x].line), create_int(y));
		add_node_in_node(&((lem->node)[y].line), create_int(x));
		lem->node[x].name = (link->name)[0];
		lem->node[y].name = (link->name)[1];
		link = link->next;
	}
}

t_node			*create_node(int count_rooms)
{
	t_node	*new;
	int		i;

	i = 0;
	if (!(new = (t_node*)malloc(sizeof(t_node) * count_rooms)))
		return (NULL);
	while (i < count_rooms)
	{
		new[i].line = NULL;
		new[i].id = 2147483647;
		i++;
	}
	return (new);
}

void			create_and_get_adjacency_lists(t_graf *graf, t_lem **lem)
{
	(*lem)->node = create_node((*lem)->rooms);
	get_nodes(graf, *lem);
}
