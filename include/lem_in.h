//
// Created by Germaine Kshlerin on 2019-05-31.
//

#ifndef LEMIN_LEM_IN_H
#define LEMIN_LEM_IN_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct      s_lem
{
    int ants;
    int rooms;
    int links;
    struct s_node   *node;
    struct s_graf   *graf;

}                   t_lem;

typedef struct      s_graf
{
    char            *start;
    char            *end;
    struct s_rooms  *rooms;
    struct s_link   *link;
}                   t_graf;

typedef struct			s_node
{
    int					id;
    char				*name;
    struct s_int		*line;
}						t_node;

typedef struct		s_int
{
    int				integer;
    struct s_int	*next;
}					t_int;

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

t_graf              *create_graf();
t_lem               *create_lem(void);
t_int	            *create_int(int integer);
t_rooms             *create_room(char *param);
t_char              *create_char(int line);
t_char              *str_to_char(char *inform);
t_char              *push_char(t_char **inform, t_char *next);
void                clear_array(char ***str);
void                print_inform(t_char *inform);
void                ants(t_lem **lem, t_char **inform);
void                parsing_lem(t_lem **lem, t_char **inform);
void                data (t_graf **graf, t_lem **lem, t_char **inform);
void                create_and_get_adjacency_lists (t_graf *graf, t_lem **lem);
void                communication_rooms(t_lem **lem, t_graf **graf, char **line);
int                 check_for_numbers(char *param);
int                 check_exist_ant(char *line, char i);
int                 validity_of_parameters(char **params);
int                 check_rooms(t_lem **lem, t_graf **graf, char **line);
int                 map_with_hash(char *line, t_lem **lem, t_graf **graf, t_char **inf);

#endif
