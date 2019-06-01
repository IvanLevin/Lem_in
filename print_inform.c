#include "./include/lem_in.h"

void print_inform(t_char *inform)
{
    while (inform)
    {
        ft_putchar(inform->letter);
        inform = inform->next;
    }
}


