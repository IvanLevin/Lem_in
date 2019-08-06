NAME = lem-in

SRC = ./src/
PARS = $(SRC)parser/
SOLVE = $(SRC)solver/

LEM_IN = $(SRC)main.c \
		$(PARS)another_func.c $(PARS)ants.c $(PARS)check_rooms.c \
		$(PARS)clear.c $(PARS)clear_create_group.c $(PARS)clear_one_char.c \
		$(PARS)clear2.c $(PARS)clear3.c $(PARS)communication_rooms.c \
		$(PARS)create_and_get_adjacency_lists.c $(PARS)create_of_structures.c \
		$(PARS)create.c $(PARS)data.c $(PARS)groups.c $(PARS)parsing_lem.c \
		$(PARS)print_inform.c $(PARS)push_int.c $(PARS)push_stream.c \
		$(PARS)run_ants.c $(PARS)shift_int.c $(PARS)work_with_map.c \
		$(SOLVE)del_conntecting.c $(SOLVE)part_one.c $(SOLVE)part_two.c \
		$(SOLVE)solve.c

DRAW = draw/
READ = read/
CONTROL = control/

# FDF =  $(SRC)$(STRUCT)push.c \
# 		$(SRC)$(DRAW)draw.c $(SRC)$(DRAW)mtrx.c $(SRC)$(DRAW)run_points.c $(SRC)$(DRAW)print.c \
# 		$(SRC)$(READ)read.c \
# 		$(SRC)$(CONTROL)control.c \

ROOT = $(LEM_IN) #$(FDF)

OBJ=$(ROOT:.c=.o)
CC = clang
CFLAGS = -g #-fsanitize=address #-Wall -Wextra -Werror
LIB = libft/libft.a
LIBDIR = libft/
LIBSPATH = -I libft/ -I /usr/local/include/ 
HDR = fdf.h
# LINK = -lmlx -framework OpenGL -framework AppKit -L /usr/local/lib/

all: lib $(OBJ) $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(LIBSPATH) get_next_line/*.c  -o $(NAME) $(LIB) $(OBJ)

lib:
	make -C $(LIBDIR)

%.o: %.c $(HDR) $(LIB)
	$(CC) $(CFLAGS) -c $< -o $@ -g

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBDIR) fclean

clean: cleanlib
	/bin/rm -f $(OBJ)

cleanlib:
	make -C $(LIBDIR) clean

re: fclean all
