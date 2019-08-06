/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:23:37 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/03 15:31:13 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		unshift_ant(t_ants **begin_list, t_ants *data)
{
	t_ants	*next;

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

void	ants(t_lem **lem, t_char **inform)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	if (!line)
		exit(EXIT_FAILURE);
	*inform = str_to_char(line);
	push_char(inform, create_char('\n'));
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
			i++;
		else
		{
			printf("\n Error 2 \n");
			exit(EXIT_FAILURE);
		}
	}
	(*lem)->ants = ft_atoi(line);
	free(line);
}
