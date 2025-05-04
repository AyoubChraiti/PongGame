CC      := cc
CFLAGS  := #-Wall -Wextra -Werror

RAYLIB_PREFIX := $(shell brew --prefix raylib)
INCLUDES := -I$(RAYLIB_PREFIX)/include
LDFLAGS  := -L$(RAYLIB_PREFIX)/lib -lraylib \
            -framework CoreVideo -framework IOKit -framework Cocoa -framework OpenGL

SRC     := $(wildcard *.c)
OBJ     := $(SRC:.c=.o)
NAME    := game

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
