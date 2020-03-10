##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A Makefile to compile solver and generator
##

all:
		(cd solver; make all)
		(cd generator; make all)

clean:
		(cd solver; make clean)
		(cd generator; make clean)

fclean:
		(cd solver; make fclean)
		(cd generator; make fclean)

re:
	(cd solver; make re)
	(cd generator; make re)

tests_run:
			(cd solver; make tests_run)
			(cd generator; make tests_run)