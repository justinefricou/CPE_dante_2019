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
    for (int i = 0; i < maze.nb_lines; i++) {
        for (int j = 0; j < maze.nb_cols; j++)
            display_cell(maze.array[i][j]);
        if (i != maze.nb_lines - 1)
            write(1, "\n", 1);
    }
}

void display_cell(int cell)
{
    if (cell == -3)
        write(1, "o", 1);
    else if (cell == -1)
        write(1, "X", 1);
    else
        write(1, "*", 1);
}

void my_put_str(char *str, int file_descr)
{
    int length_str = 0;

    for ( ; str[length_str] != 0; length_str++);
    write(file_descr, str, length_str);
}