/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:24:24 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/02 16:24:25 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/lem_in.h"

t_rooms *create_room(char *param)
{
    t_rooms *new;

    if (!(new = (t_rooms*)malloc(sizeof(t_rooms))))
        exit(EXIT_FAILURE);
    new->name = param;
    new->next = NULL;
    return (new);
}

int			*create_mas(int len)
{
    int	*mas;
    int n;

    n = 0;
    mas = (int *)malloc(sizeof(int) * len);
    while (n < len)
    {
        mas[n] = 0;
        n++;
    }
    return (mas);
}

t_stream	*create_stream(int *used, t_int *turn)
{
    t_stream	*new;

    if (!(new = (t_stream*)ft_memalloc(sizeof(t_stream))))
        exit(EXIT_FAILURE);
    new->len = 0;
    new->used = used;
    new->turn = turn;
    new->next = NULL;
    return (new);
}

t_ants		*create_ant(int name, t_stream *stream)
{
    t_ants	*new;

    if (!(new = (t_ants*)ft_memalloc(sizeof(t_ants))))
        exit(EXIT_FAILURE);
    new->name = name;
    new->rooms = 0;
    new->stream = stream;
    new->next = NULL;
    return (new);
}
