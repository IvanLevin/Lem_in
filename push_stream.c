#include "include/lem_in.h"

int		push_stream(t_stream **begin_list, t_stream *data)
{
    t_stream	*next;

    if (!data)
        return (1);
    next = *begin_list;
    if (next)
    {
        while (next->next)
            next = next->next;
        next->next = data;
    }
    else
        *begin_list = data;
    return (0);
}
