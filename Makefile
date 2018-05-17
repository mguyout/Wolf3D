SRCS = main.c hooks.c initcheck.c print.c ft_mallocat.c ft_malloc.c

OBJS = $(SRCS:.c=.o)

CFLAGS = 

CC = gcc

NAME = wolf3d

LIBS = libft/libft.a\

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C ./minilibx_macos
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME) -framework OpenGL -framework AppKit -I minilibx_macos ./minilibx_macos/libmlx.a

clean:
	rm -rf $(OBJS)
	make -C ./libft clean
	make -C ./minilibx_macos clean 

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all

