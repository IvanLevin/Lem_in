#include "./include/lem_in.h"

void data(t_graf **graf, t_lem **lem, t_char **inform)
{
    char    *line;

    line = NULL;
    int i = 0;
    while (get_next_line(0, &line))
    {
        push_char(inform, str_to_char(line));
        push_char(inform, create_char('\n'));
        if (map_with_hash(line, lem, graf, inform))
            continue;
        communication_rooms(lem, graf, &line);
    }

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

    // 3. Стартовая и финальная комната
    printf("start = %s\n", (*graf)->start);
    printf("end = %s\n", (*graf)->end);
}