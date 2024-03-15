NAME = gg

CC = cc

INCLUDES = lib/libft.a

all: $(NAME)

$(NAME):
	$(CC) *.c  -L lib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT \
		-framework OpenGL lib/libraylib.a -o game


fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean re all fclean