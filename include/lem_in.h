//
// Created by Germaine Kshlerin on 2019-05-31.
//

#ifndef LEMIN_LEM_IN_H
#define LEMIN_LEM_IN_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct          s_lem
{
    int                 ants;
    int                 rooms;
    struct s_node       *node;
    struct s_graf       *graf;

}                       t_lem;

typedef struct          s_graf
{
    char                *start;
    char                *end;
    struct s_rooms      *rooms;
    struct s_link       *link;
}                       t_graf;

typedef struct          s_node
{
    int				    id;
    char			    *name;
    struct s_int	    *line;
}					    t_node;

typedef struct		    s_int
{
    int				    integer;
    struct s_int	    *next;
}					    t_int;

typedef struct          s_rooms
{
    char                *name;
    struct s_rooms      *next;
}                       t_rooms;

typedef struct			s_stream
{
    int					len;
    int					*used;
    struct s_int		*turn;
    struct s_stream		*next;
}						t_stream;

typedef struct			s_groups
{
    int					count;
    struct s_stream		*stream;
    struct s_groups		*next;
}						t_groups;

typedef struct			s_ants
{
    int					rooms;
    int					name;
    struct s_stream		*stream;
    struct s_ants		*next;
}                       t_ants;

typedef struct          s_char
{
    int                 letter;
    struct s_char       *next;
}                       t_char;

typedef struct          s_link
{
    char                **name;
    struct s_link       *next;
}                       t_link;

t_graf              *create_graf();
t_lem               *create_lem(void);
t_int	            *create_int(int integer);
t_rooms             *create_room(char *param);
t_char              *create_char(int line);
t_char              *str_to_char(char *inform);
t_char              *push_char(t_char **inform, t_char *next);
void                clear_array(char ***str);
void		        clear_char(t_char **letter);
void                print_inform(t_char *inform);
void		        clear_one_char(t_char **letter);
void                ants(t_lem **lem, t_char **inform);
void	            run_ants(t_lem *lem, t_stream **streams);
void                parsing_lem(t_lem **lem, t_char **inform);
void                data (t_graf **graf, t_lem **lem, t_char **inform);
void	            to_let_out(t_lem *lem, t_groups *groups, t_ants **ants);
void                create_and_get_adjacency_lists (t_graf *graf, t_lem **lem);
void                communication_rooms(t_lem **lem, t_graf **graf, char **line);
void	            put_way_ants(t_lem *lem, t_stream *streams, t_groups *groups);
int                 check_for_numbers(char *param);
void		clear_streams(t_stream **streams);
int                 check_exist_ant(char *line, char i);
int                 validity_of_parameters(char **params);
int		            put_step_ants(t_lem *lem, t_ants *ants);
int                 check_rooms(t_lem **lem, t_graf **graf, char **line);
int                 map_with_hash(char *line, t_lem **lem, t_graf **graf, t_char **inf);
void				set_groups(t_lem *lem, t_stream *streams, t_groups **groups);
t_groups	*create_group(t_stream *stream);
int		unshift_groups(t_groups **begin_list, t_groups *data);
void			clear_groups(t_groups **groups);
void			clear_ants(t_ants **ants);
t_ants		*create_ant(int name, t_stream *stream);
int		unshift_ant(t_ants **begin_list, t_ants *data);
void		clear_lem(t_lem **lem);
void		clear_row(t_node **node, int rooms);
void			clear_graf(t_graf **graf);
void		clear_link(t_link **link);
void		clear_rooms(t_rooms **rooms);



#endif
