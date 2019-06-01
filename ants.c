#include "include/lem_in.h"

void ants(t_lem **lem, t_char **inform)
{
    char *line;
    int  i;

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
            printf("ERROR!");
            exit(EXIT_FAILURE);
        }
    }
    (*lem)->ants = ft_atoi(line);
    free(line);
}