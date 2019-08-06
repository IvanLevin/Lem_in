/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:25:40 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/02 16:25:41 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int	shift_int(t_int **integer)
{
	t_int	*update;
	int		answer;

	if (!*initgroups)
		return (-2);
	answer = (*integer)->integer;
	update = (*integer)->next;
	free(*integer);
	*integer = update;
	return (answer);
}
