/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:25:21 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/02 16:25:22 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		push_int(t_int **begin_list, t_int *data)
{
	t_int	*next;

	if (!data)
		return (1);
	next = *begin_list;
	if (next)
	{
		while (next->next)
			next = next->next;
		next->next = data;
	}
	else
		*begin_list = data;
	return (0);
}
