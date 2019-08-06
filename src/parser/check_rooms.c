/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:25:01 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/03 15:35:10 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		check_valid_room(t_rooms *room, char *param)
{
	while (room)
	{
		if (!ft_strcmp(room->name, param))
			return (0);
		room = room->next;
	}
	return (1);
}

void	add_room_in_graf(t_rooms **graf_rom, t_rooms **room)
{
	t_rooms *new_room;

	new_room = *graf_rom;
	if (new_room)
	{
		while (new_room->next)
			new_room = new_room->next;
		new_room->next = *room;
	}
	else
		*graf_rom = *room;
}

void	get_name_rooms(t_lem **lem, t_graf **graf, char **line)
{
	char	**param;
	t_rooms	*room;

	param = ft_strsplit(*line, ' ');
	if (validity_of_parameters(param) != 3 && check_for_numbers(param[1]) &&
	check_for_numbers(param[2]))
	{
		printf("\n Error 8 \n");
		exit(EXIT_FAILURE);
	}
	if (check_valid_room((*graf)->rooms, param[0]))
	{
		room = create_room(ft_strdup(param[0]));
		add_room_in_graf(&(*graf)->rooms, &room);
	}
	(*lem)->rooms += 1;
	clear_array(&param);
	free(*line);
}

int		count_arr_ch(char **str)
{
	int		n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int		check_rooms(char **line)
{
	char	**param;
	int		answer;

	if (!line)
		exit(EXIT_FAILURE);
	param = ft_strsplit(*line, ':');
	if (count_arr_ch(param) != 2)
		answer = 0;
	else if (!ft_strcmp(param[0], "#Here is the number of lines required"))
	{
		free(*line);
		answer = 1;
	}
	else
		answer = 0;
	clear_array(&param);
	return (answer);
}
