##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for organized project
##

SRC = $(shell find . -type f -name "*.c" ! -name "tests*")
LIB = $(shell find . -type f -name "*.a")
OBJ = 	$(SRC:%.c=build/%.o)
DEBUG_FLAGS = -g3 -Iinclude -fsanitize=address
CFLAGS += -Iinclude -g3
NAME = organized
DEBUG_NAME = debug

build/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

build-debug/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

$(DEBUG_NAME): $(OBJ)
	gcc -o $(DEBUG_NAME) $(OBJ) $(LIB) $(DEBUG_FLAGS)

clean:
	find . -type f -name "*.o" -delete

fclean: clean
	rm -rf build
	rm -f organized
	rm -f debug

re: fclean all
