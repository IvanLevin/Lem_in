#include "./include/lem_in.h"

t_link *creat_link(char **param)
{
    t_link  *new;

    if (!(new = (t_link*)ft_memalloc(sizeof(t_link))))
        exit(EXIT_FAILURE);
    new->name = param;
    new->next = NULL;
    return (new);
}

int validate_parameters(char **param)
{
    int i;

    i = 0;
    while (param[i])
        i++;
    return (i);
}

int check_communication(const char *line, char i)
{
    int n;

    n = 0;
    while (line[n])
    {
        if (line[n] == i)
            return (1);
        n++;
    }
    return (0);
}

void add_link_in_graf(t_link **graf_link, t_link **link)
{
    t_link *new_link;

    new_link = *graf_link;
    if (new_link)
    {
        while (new_link->next)
            new_link = new_link->next;
        new_link->next = *link;
    }
    else
        *graf_link = *link;
}

void get_communication(t_lem **lem, t_graf **graf, char **line)
{
    char    **param;
    t_link  *link;

    param = ft_strsplit(*line, '-');
    if (validate_parameters(param) != 2)
        exit(EXIT_FAILURE);
    link = creat_link(param);
    add_link_in_graf(&(*graf)->link, &link);
    free(*line);
}

void communication_rooms(t_lem **lem, t_graf **graf, char **line)
{
    if (!line)
        exit(EXIT_FAILURE);
    else if (check_communication(*line, '-'))
        get_communication(lem, graf, line);
}