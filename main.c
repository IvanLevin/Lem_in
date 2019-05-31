

#include "include/lem_in.h"

static void lem_in()
{
    t_lem   *lem;
    t_char  *inform;

    inform = NULL;
    parsing_lim(&lem, &inform);

}




int main(void)
{
    lem_in();
    return (0);
}