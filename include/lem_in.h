//
// Created by Germaine Kshlerin on 2019-05-31.
//

#ifndef LEMIN_LEM_IN_H
#define LEMIN_LEM_IN_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"

// коллчество муравьев
// кол - во комнат
// структура графа
typedef struct      s_lem
{
    int ants;
    int rooms;
    int links;
    struct s_graf   *graf;
}                   t_lem;

// начало графа
// конец графа
// структура комнат
typedef struct      s_graf
{
    char            *start;
    char            *end;
    struct s_rooms  *rooms;
    struct s_link   *link;
}                   t_graf;

// имя комнаты
// структура следующей комнаты
typedef struct      s_rooms
{
    char            *name;
    struct s_rooms  *next;
}                   t_rooms;

typedef struct      s_char
{
    int             letter;
    struct s_char   *next;
}                   t_char;

typedef struct      s_link
{
    char            **name;
    struct s_link   *next;
}                   t_link;

void    parsing_lem(t_lem **lem, t_char **inform);
t_graf  *create_graf();
t_lem   *create_lem(void);
void    ants(t_lem **lem, t_char **inform);
t_char  *create_char(int line);
t_char  *push_char(t_char **inform, t_char *next);
void    data (t_graf **graf, t_lem **lem, t_char **inform);
t_char  *str_to_char(char *inform);
void    print_inform(t_char *inform);
int     map_with_hash(char *line, t_lem **lem, t_graf **graf, t_char **inf);
int     validity_of_parameters(char **params);
void    clear_array(char ***str);
int     check_rooms(t_lem **lem, t_graf **graf, char **line);
int     check_exist_ant(char *line, char i);
int     check_for_numbers(char *param);
void communication_rooms(t_lem **lem, t_graf **graf, char **line);

#endif
