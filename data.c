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

static void add_to_start_in_graf(t_rooms **rooms, char *start)
{
    t_rooms *room;
    t_rooms *next;

    if(!(room = create_room(ft_strdup(start))))
        return exit(EXIT_FAILURE);
    next = *rooms;
    if (next)
    {
        while(next->next)
            next = next->next;
        next->next = room;
    }
    else
        *rooms = room;
}

static void add_to_end_in_graf(t_rooms **rooms, char *end)
{
    t_rooms *room;
    t_rooms *next;

    if(!(room = create_room(ft_strdup(end))))
        return exit(EXIT_FAILURE);
    next = *rooms;
    if (next)
    {
        while(next->next)
            next = next->next;
        next->next = room;
    }
    else
        *rooms = room;
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
    add_to_start_in_graf(&(*graf)->rooms, (*graf)->start);
    add_to_end_in_graf(&(*graf)->rooms, (*graf)->end);
    check_repeat_rooms((*graf)->rooms);

            // ПРОВЕРКА НА УСПЕШНОСТЬ СОХРАНЕНЫХ ДАННЫХ
    // 1. Связи
    while ((*graf)->link)
    {
        printf("link from %s ", (*graf)->link->name[0]);
        printf("link to %s\n ", (*graf)->link->name[1]);
        (*graf)->link = (*graf)->link->next;
    }
    // 2. Имена комнат
    while ((*graf)->rooms)
    {
        printf("Rooms: %s \n", (*graf)->rooms->name);
        (*graf)->rooms = (*graf)->rooms->next;
    }
    printf("\n");
    printf("Колличество комнат ");
    printf("%d\n", (*lem)->rooms);
}