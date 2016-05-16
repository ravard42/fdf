CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fdf
SRC =	main.c\
		parsing.c\
		env_funct.c\
		draw_line.c\
		rot_funct.c\

OBJ = $(SRC:.c=.o)
INCLUDE = includes/
MINILIBX_L = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): ./libft/libft.a $(OBJ) 
	$(CC) -o $(NAME) $(OBJ) -I $(INCLUDE) -L libft/ -lft $(MINILIBX_L) $(FLAGS)

./libft/libft.a :
	make -C libft/

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCLUDE) $(FLAGS)

clean:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
