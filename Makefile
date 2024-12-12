##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for organized project
##

SRC = $(shell find . -type f -name "*.c" ! -path "./tests/*")
SRC_TESTS = $(shell find . -type f -name "*.c" ! -name "main.c")
LIB = $(shell find . -type f -name "*.a")
OBJ = 	$(SRC:%.c=build/%.o)
OBJ_DEBUG = 	$(SRC:%.c=build-debug/%.o)
OBJS_TESTS = $(SRC_TESTS:%.c=build-tests/%.o)
DEBUG_FLAGS = -g3 -Iinclude -fsanitize=address
TEST_FLAGS = -Iinclude --coverage -lgcov -lcriterion
CFLAGS += -Iinclude
NAME = organized
DEBUG_NAME = debug
TEST_NAME = test_organized

build/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

build-debug/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(DEBUG_FLAGS) -c $< -o $@

build-tests/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(TEST_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

$(DEBUG_NAME): $(OBJ_DEBUG)
	gcc -o $(DEBUG_NAME) $(OBJ_DEBUG) $(LIB) $(DEBUG_FLAGS)

tests_run: $(OBJS_TESTS)
	gcc -o $(TEST_NAME) $(OBJS_TESTS) $(TEST_FLAGS)
	./test_organized

show_test: tests_run
	gcovr -r . --html --html-details -o coverage/index.html
	firefox coverage/index.html

clean:
	find . -type f -name "*.o" -delete

fclean: clean
	rm -rf build
	rm -rf build-debug
	rm -rf build-tests
	rm -f organized
	rm -f debug
	rm -f test_organized

re: fclean all
