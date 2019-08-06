/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:24:04 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/02 16:24:08 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void	parsing_lem(t_lem **lem, t_char **inform)
{
	t_graf	*graf;

	graf = create_graf();
	*lem = create_lem();
	ants(lem, inform);
	data(&graf, lem, inform);
	create_and_get_adjacency_lists(graf, lem);
	(*lem)->graf = graf;
}
