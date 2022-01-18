HEADER=fractol.h

SRC_FILE = main.c utils.c mandelbrot.c julia.c \
			burningship.c utils2.c\

NAME = fractol
OBJ_FILE = $(SRC_FILE:.c=.o)
all: $(NAME)

$(NAME):	$(OBJ_FILE) $(HEADER)
		gcc -Wall -Wextra -Werror -lmlx -framework OpenGl -framework Appkit $(OBJ_FILE) -o $(NAME)

%.o: %.c ${HEADER}
		gcc -Wall -Wextra -Werror  -c $< -o $@

clean:
	rm -f $(OBJ_FILE)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
.PHONY : all clean fclean re