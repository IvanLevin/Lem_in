/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:26:17 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/02 16:26:20 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
t_char              *create_char(int line);
t_int	            *create_int(int integer);
t_rooms             *create_room(char *param);
t_char              *str_to_char(char *inform);
t_groups	        *create_group(t_stream *stream);
t_stream	        *create_stream(int *used, t_int *turn);
t_ants		        *create_ant(int name, t_stream *stream);
void			    part1(t_lem *lem);
void		        clear_lem(t_lem **lem);
void                clear_array(char ***str);
void			    clear_ants(t_ants **ants);
void			    clear_graf(t_graf **graf);
void		        clear_link(t_link **link);
void		        clear_char(t_char **letter);
void		        clear_rooms(t_rooms **rooms);
void                print_inform(t_char *inform);
void			    clear_groups(t_groups **groups);
void		        clear_one_char(t_char **letter);
void		        clear_streams(t_stream **streams);
void                ants(t_lem **lem, t_char **inform);
void		        clear_row(t_node **node, int rooms);
void			    part2(t_lem *lem, t_stream *stream);
void			    del_connecting(t_lem *lem, int *used);
void			    solve(t_lem *lem, t_stream **streams);
void	            run_ants(t_lem *lem, t_stream **streams);
void                parsing_lem(t_lem **lem, t_char **inform);
void                data (t_graf **graf, t_lem **lem, t_char **inform);
void	            to_let_out(t_lem *lem, t_groups *groups, t_ants **ants);
void                create_and_get_adjacency_lists (t_graf *graf, t_lem **lem);
void				set_groups(t_lem *lem, t_stream *streams, t_groups **groups);
void                communication_rooms(t_lem **lem, t_graf **graf, char **line);
void	            put_way_ants(t_lem *lem, t_stream *streams, t_groups *groups);
int			        *create_mas(int len);
int	                shift_int(t_int **integer);
int                 check_for_numbers(char *param);
int                 check_exist_ant(char *line, char i);
int                 validity_of_parameters(char **params);
int		            put_step_ants(t_lem *lem, t_ants *ants);
int		            push_int(t_int **begin_list, t_int *data);
int                 push_char(t_char **begin_list, t_char *data);
int		            unshift_ant(t_ants **begin_list, t_ants *data);
int		            push_rooms(t_rooms **begin_list, t_rooms *data);
int		            push_stream(t_stream **begin_list, t_stream *data);
int                 check_rooms(t_lem **lem, t_graf **graf, char **line);
int		            unshift_groups(t_groups **begin_list, t_groups *data);
int                 map_with_hash(char *line, t_lem **lem, t_graf **graf, t_char **inf);

#endif
