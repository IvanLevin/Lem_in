//
// Created by Germaine Kshlerin on 2019-06-30.
//

#include "include/lem_in.h"

static int		add_node_in_node(t_int **link, t_int *data)
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

static int find_position(t_rooms *rooms, char *name_room, int count)
{
    while (rooms)
    {
        count--;
        if (!ft_strcmp(rooms->name, name_room))
            return (count);
        rooms = rooms->next;
    }
    exit(EXIT_FAILURE);
}

static  void    get_nodes(t_graf *graf, t_lem *lem)
{
    t_link *link;
    int     x;
    int     y;

    link = graf->link;
    while (link)
    {
        x = find_position(graf->rooms, link->name[0], lem->rooms);
        y = find_position(graf->rooms, link->name[1], lem->rooms);
        add_node_in_node(&((lem->node)[x].line), create_int(y));
        add_node_in_node(&((lem->node)[y].line), create_int(x));
        link = link->next;
    }
}

static  t_node *create_node(int count_rooms)
{
    t_node  *new;
    int     i;

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

void            create_and_get_adjacency_lists (t_graf *graf, t_lem **lem)
{
    if (((*lem)->node = create_node((*lem)->rooms)) == NULL)
        return exit(EXIT_FAILURE);
    get_nodes(graf, *lem);
}