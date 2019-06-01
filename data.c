#include "./include/lem_in.h"

void data (t_graf **graf, t_lem **lem, t_char **inform)
{
    char *line;

    line = NULL;
    while (get_next_line(0, &line))
    {
        push_char(inform, str_to_char(line));
        push_char(inform, create_char('\n'));
        map_with_hash(line, lem, graf, inform);

    }
}