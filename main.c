
#include "include/lem_in.h"

static void lem_in()
{
    t_lem       *lem;
    t_char      *inform;
    t_stream	*streams;

    inform = NULL;
    parsing_lem(&lem, &inform);
    print_inform(inform);
    ft_putendl("");
    run_ants(lem, &streams);
    clear_char(&inform);
    clear_streams(&streams);
    clear_lem(&lem);

}

int main(void)
{
    lem_in();
    return (0);
}