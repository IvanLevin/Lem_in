#include "include/lem_in.h"

t_graf *create_graf(void)
{
    t_graf *new;

     if (!(new = (t_graf*)malloc(sizeof(t_graf))))
         return (NULL);
     new->start = 0;
     new->end = 0;
     new->rooms = NULL;
    return (new);
}

t_lem *create_lem(void)
{
    t_lem *new;

    if (!(new = (t_lem*)malloc(sizeof(t_lem))))
        return (NULL);
    new->ants = 0;
    new->rooms = 2;
    new->graf = NULL;
    return (new);
}

t_char *create_char(char *line)
{
    t_char *new;

    if (!(new = (t_char*)malloc(sizeof(t_char))))
        return (NULL);
    new->letter = line;
    new->next = NULL;
    return (new);
}

t_char *push_char(t_char **inform, t_char *next)
{
    t_char *save_struct;

    save_struct = *inform;
    if (save_struct)
    {
        while (save_struct->next)
            save_struct = save_struct->next;
        save_struct->next = next;
    }
    else
        *inform = next;
    return (0);
}
