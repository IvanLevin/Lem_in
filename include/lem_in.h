//
// Created by Germaine Kshlerin on 2019-05-31.
//

#ifndef LEMIN_LEM_IN_H
#define LEMIN_LEM_IN_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct  s_lem
{
    int ants;
    int rooms;
    struct s_graf   *graf;
}   t_lem;

typedef struct  s_graf
{
    int start;
    int end;
    struct s_rooms *rooms;
}   t_graf;

typedef struct s_rooms
{
    char *name;
    struct s_rooms *next;
}   t_rooms;

typedef struct s_char
{
    char *letter;
    struct s_char *next;

}t_char;

void parsing_lim(t_lem **lem, t_char **inform);
t_graf *create_graf();
t_lem *create_lem(void);
void ants(t_lem **lem, t_char **inform);
t_char *create_char(char *line);
t_char *push_char(t_char **inform, t_char *next);

#endif
