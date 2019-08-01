#include "./include/lem_in.h"

t_ants		*create_ant(int name, t_stream *stream)
{
    t_ants	*new;

    if (!(new = (t_ants*)ft_memalloc(sizeof(t_ants))))
        exit(EXIT_FAILURE);
    new->name = name;
    new->rooms = 0;
    new->stream = stream;
    new->next = NULL;
    return (new);
}
