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

int check_valid_room(t_rooms **room, char **param)
{
    t_rooms *next;

    next = *room;
    if (next)
        while (next)
        {
            if (!ft_strcmp(next->name, param[0]))
                exit(EXIT_FAILURE);
            next = next->next;
        }
    return (1);
}

void add_room_in_graf(t_rooms **graf_rom, t_rooms **room)
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

void get_name_rooms(t_lem **lem, t_graf **graf, char **line)
{
    char    **param;
    t_rooms *room;

    param = ft_strsplit(*line, ' ');
    if (validity_of_parameters(param) != 3 && check_for_numbers(param[1]) &&
    check_for_numbers(param[2]))
        exit(EXIT_FAILURE);
    if (check_valid_room(&(*graf)->rooms, &param[0]))
    {
        room = create_room(ft_strdup(param[0]));
        add_room_in_graf(&(*graf)->rooms, &room);
    }
    (*lem)->rooms += 1;
    clear_array(&param);
    free(*line);
}

int check_rooms(t_lem **lem, t_graf **graf, char **line)
{
    if (!line)
        exit(EXIT_FAILURE);
    else if (check_exist_ant(*line, ' '))
    {
        get_name_rooms(lem, graf, line);
        return (1);
    }
    return (0);
}
