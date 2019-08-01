#include "include/lem_in.h"

int		unshift_ant(t_ants **begin_list, t_ants *data)
{
    t_ants	*next;

    if (!data)
        return (1);
    next = *begin_list;
    if (next)
    {
        data->next = *begin_list;
        *begin_list = data;
    }
    else
        *begin_list = data;
    return (0);
}

void    ants(t_lem **lem, t_char **inform)
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
            exit(EXIT_FAILURE);
    }
    (*lem)->ants = ft_atoi(line);
    free(line);
}