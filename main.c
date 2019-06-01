
#include "include/lem_in.h"

static void lem_in()
{
    t_lem   *lem;
    t_char  *inform;

    inform = NULL;
    parsing_lem(&lem, &inform);
    print_inform(inform);
}

int main(void)
{
    lem_in();
    return (0);
}