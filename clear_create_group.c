/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_create_group.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:45:23 by breolson          #+#    #+#             */
/*   Updated: 2019/08/03 15:45:25 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/lem_in.h"

t_groups	*create_group(t_stream *stream)
{
	t_groups	*new;

	if (!(new = (t_groups*)ft_memalloc(sizeof(t_groups))))
		exit(EXIT_FAILURE);
	new->count = 1;
	new->stream = stream;
	new->next = NULL;
	return (new);
}

int			unshift_groups(t_groups **begin_list, t_groups *data)
{
	t_groups	*next;

	if (!data)
		return (1);
	next = *begin_list;
	if (next)
	{
		data->next = *begin_list;
		*begin_list = data;
	}
	else
		*begin_list = data;
	return (0);
}
