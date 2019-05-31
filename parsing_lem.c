#include "include/lem_in.h"

void parsing_lim(t_lem **lem, t_char **inform)
{
    t_graf  *graf;

    graf = create_graf();
    *lem = create_lem();
    ants(lem, inform);
}
