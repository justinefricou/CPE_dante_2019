##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A Makefile to compile solver
##

NAME	=	solver

SRC	=	main.c\
		src/get_maze.c\
		src/get_maze_as_int_matrix.c\
		src/error_detection.c\
		src/solve_maze.c\
		src/coordinates.c\
		src/display.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -I./

NAME_TESTS	=	tests_solver

SRC_TESTS	=

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_TESTS)

fclean:	clean
		rm -f $(NAME)
		rm -f $(NAME_TESTS)
		rm -f *.gcno
		rm -f *.gcda

re:	fclean all

tests_run:	$(SRC_TESTS)
			rm -f *.gcno
			rm -f *.gcda
			gcc -o $(NAME_TESTS) $(SRC_TESTS) $(CFLAGS) --coverage -lcriterion
			./$(NAME_TESTS)