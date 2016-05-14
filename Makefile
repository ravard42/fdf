CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fdf
SRC =	gnl_src/get_next_line.c\
	main.c\
	parsing.c\
	env_funct.c\
	draw_line.c\
	rot_funct.c\

OBJ = $(SRC:.c=.o)
INCLUDE = includes/
MINILIBX_L = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): ./libft_src/libft.a $(OBJ) 
	$(CC) -o $(NAME) $(OBJ) -I $(INCLUDE) -L libft_src/ -lft $(MINILIBX_L) $(FLAGS)

./libft_src/libft.a :
	make -C libft_src/

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCLUDE) $(FLAGS)

clean:
	rm -f $(OBJ)
	make -C libft_src/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
