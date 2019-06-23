#include "./include/lem_in.h"

int check_for_numbers(char *param)
{
    int i;

    i = 0;
    while(param[i])
    {
        if (param[i] >= '0' && param[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}

int validity_of_parameters(char **params)
{
    int i;

    i = 0;
    while (params[i])
        i++;
    return (i);
}

void clear_array(char ***str)
{
    int i;

    i = 0;
    while ((*str)[i])
    {
        free((*str)[i]);
        (*str)[i] = NULL;
        i++;
    }
    free(*str);
    *str = NULL;
}

int check_exist_ant(char *line, char i)
{
    int n;

    n = 0;
    while (line[n])
    {
        if (line[n] == i)
            return (1);
        n++;
    }
    return (0);
}

