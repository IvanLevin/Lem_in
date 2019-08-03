#include "./include/lem_in.h"

static  void save_end(t_lem **lem, t_graf **graf, t_char **inf)
{
    char *line;
    char **get_end;

    line = NULL;
    get_next_line(0, &line);
    push_char(inf, str_to_char(line));
    push_char(inf, create_char('\n'));
    get_end = ft_strsplit(line, ' ');
    if (validity_of_parameters(get_end) != 3)
    {
        printf("Not 3 params in list. Error");
        exit(EXIT_FAILURE);
    }
    (*graf)->end = ft_strdup(get_end[0]);
    free(line);
    clear_array(&get_end);
}

static  void save_start(t_graf **graf, t_char **inf)
{
    char *line;
    char **get_start;

    line = NULL;
    get_next_line(0, &line);
    push_char(inf, str_to_char(line));
    push_char(inf, create_char('\n'));
    get_start = ft_strsplit(line, ' ');
    if (validity_of_parameters(get_start) != 3)
    {
        printf("Not 3 params in list. Error");
        exit(EXIT_FAILURE);
    }
    (*graf)->start = ft_strdup(get_start[0]);
    free(line);
    clear_array(&get_start);
}

int map_with_hash(char **line, t_lem **lem, t_graf **graf, t_char **inf)
{
    if (!ft_strcmp(*line, "##start"))
    {
        if ((*graf)->start)
            exit(EXIT_FAILURE);
        free(*line);
        save_start(graf, inf);
        return (1);
    }
    else if (!ft_strcmp(*line, "##end"))
    {
        if ((*graf)->end)
            exit(EXIT_FAILURE);
        free(*line);
        save_end(lem, graf, inf);
        return (1);
    }
    else if (!ft_strcmp(*line, "#comment") ||
    !ft_strcmp(*line, "#another comment"))
    {
        free(*line);
        return (1);
    } else
        return (check_rooms(line));
}


