/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:26:23 by breolson          #+#    #+#             */
/*   Updated: 2019/08/03 15:27:24 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

t_int	*create_int(int integer)
{
	t_int	*new;

	if (!(new = (t_int*)ft_memalloc(sizeof(t_int))))
		exit(EXIT_FAILURE);
	new->integer = integer;
	new->next = NULL;
	return (new);
}

int		check_for_numbers(char *param)
{
	int i;

	i = 0;
	while (param[i])
	{
		if (param[i] >= '0' && param[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int		validity_of_parameters(char **params)
{
	int i;

	i = 0;
	while (params[i])
		i++;
	return (i);
}

void	clear_array(char ***str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		(*str)[i] = NULL;
		i++;
	}
	free(*str);
	*str = NULL;
}

int		check_exist_ant(char *line, char i)
{
	int n;

	n = 0;
	while (line[n])
	{
		if (line[n] == i)
			return (1);
		n++;
	}
	return (0);
}
