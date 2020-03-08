##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A Makefile to compile solver and generator
##

all:
		(cd solver; make all)

clean:
		(cd solver; make clean)

fclean:
		(cd solver; make fclean)

re:
	(cd solver; make re)

tests_run:
			(cd solver; make re)