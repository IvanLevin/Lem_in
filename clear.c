/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:24:37 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/03 15:36:56 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/lem_in.h"

void	clear_streams(t_stream **streams)
{
	t_stream	*next;

	while (*streams)
	{
		next = (*streams)->next;
		(void)(*streams)->len;
		free((*streams)->used);
		free(*streams);
		(*streams) = next;
	}
}

void	clear_char(t_char **letter)
{
	t_char *next;

	while (*letter)
	{
		next = (*letter)->next;
		clear_one_char(letter);
		*letter = next;
	}
}

void	clear_lem(t_lem **lem)
{
	clear_row(&(*lem)->node, (*lem)->rooms);
	clear_graf(&(*lem)->graf);
	(void)(*lem)->ants;
	(void)(*lem)->rooms;
	free(*lem);
	*lem = NULL;
}

void	clear_groups(t_groups **groups)
{
	t_groups	*next;

	while (*groups)
	{
		next = (*groups)->next;
		(void)(*groups)->count;
		(*groups)->stream = NULL;
		free(*groups);
		(*groups) = next;
	}
}

void	clear_ants(t_ants **ants)
{
	t_ants		*next;

	while (*ants)
	{
		next = (*ants)->next;
		(void)(*ants)->name;
		(void)(*ants)->rooms;
		(*ants)->stream = NULL;
		free(*ants);
		(*ants) = next;
	}
}
