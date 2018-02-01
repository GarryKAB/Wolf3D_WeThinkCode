NAME = wolf3D

SRC =	main.c\
		get_next_line.c\
		ft_count.c\
		get_x_and_y.c\
		map_read.c\
		calculations.c\
		ft_sdl_draw_stuff.c\
		floor_and_ceiling.c\
		events.c\

LIB = ./libft/libft.a

INCLUDES = -I./libft/ -I./includes/

FLAGS = -g -Wall -Werror -Wextra

TFLAGS = -lSDL2 -I ~/.brew/include -L ~/.brew/lib

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		# make -C libft/ fclean && make -C libft/
		# gcc -I ~/.brew/include -L ~/.brew/lib -o $(NAME) $(SRC) -lSDL2
		make -C libft/ fclean && make -C libft/
		clang $(FLAGS) $(TFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
		/bin/rm -f $(OBJ)
		make -C libft/clean

fclean:
		/bin/rm -f $(NAME)
		/bin/rm -f libft/libft.a
		/bin/rm -f *.o
		/bin/rm -f libft/*.o

re: fclean all