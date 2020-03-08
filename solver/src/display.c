/*
** EPITECH PROJECT, 2020
** display.c
** File description:
** Displays the solution, or a message if there isn't one.
*/

#include "solver.h"

void display_no_solution(void)
{
    my_put_str("no solution found", 1);
}

void display_solution(maze_t maze)
{
    // TODO
}

void my_put_str(char *str, int file_descr)
{
    int length_str = 0;

    for ( ; str[length_str] != 0; length_str++);
    write(file_descr, str, length_str);
}