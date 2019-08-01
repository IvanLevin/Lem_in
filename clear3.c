#include "./include/lem_in.h"

void		clear_link(t_link **link)
{
    t_link	*next;

    while (*link)
    {
        next = (*link)->next;
        free((*link)->name[0]);
        (*link)->name[0] = NULL;
        free((*link)->name[1]);
        (*link)->name[1] = NULL;
        free((*link)->name);
        (*link)->name = NULL;
        (*link)->next = NULL;
        free(*link);
        *link = next;
    }
}

void		clear_rooms(t_rooms **rooms)
{
    t_rooms		*next;

    while (*rooms)
    {
        next = (*rooms)->next;
        free((*rooms)->name);
        (*rooms)->name = NULL;
        (*rooms)->next = NULL;
        free(*rooms);
        *rooms = next;
    }
}

