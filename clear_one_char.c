#include "./include/lem_in.h"

void		clear_one_char(t_char **letter)
{
    (void)(*letter)->letter;
    (*letter)->next = NULL;
    free(*letter);
    (*letter) = NULL;
}

