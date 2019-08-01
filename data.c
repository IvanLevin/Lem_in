#include "./include/lem_in.h"

static void check_repeat_rooms(t_rooms *rooms)
{
    t_rooms *room;
    t_rooms *next;

    next = rooms;
    while (next)
    {
        room = next->next;
        while (room)
        {
            if (!(ft_strcmp(room->name, next->name)))
                exit(EXIT_FAILURE);
            room = room->next;
        }
        next = next->next;
    }
}

static  int		unshift_rooms(t_rooms **begin_list, t_rooms **data)
{
    t_rooms	*next;

    if (!*data)
        return (1);
    next = *begin_list;
    if (next)
    {
        (*data)->next = *begin_list;
        *begin_list = *data;
    }
    else
        *begin_list = *data;
    return (0);
}

static  int		push_rooms(t_rooms **begin_list, t_rooms *data)
{
    t_rooms	*next;

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

static void		set_startend(t_graf **graf)
{
    t_rooms		*room;

    push_rooms(&(*graf)->rooms, create_room(ft_strdup((*graf)->start)));
    room = create_room(ft_strdup((*graf)->end));
    unshift_rooms(&(*graf)->rooms, &room);
}

void data(t_graf **graf, t_lem **lem, t_char **inform)
{
    char    *line;

    line = NULL;
    while (get_next_line(0, &line))
    {
        push_char(inform, str_to_char(line));
        push_char(inform, create_char('\n'));
        if (map_with_hash(line, lem, graf, inform))
            continue;
        communication_rooms(lem, graf, &line);
    }
    set_startend(graf);
    check_repeat_rooms((*graf)->rooms);
}