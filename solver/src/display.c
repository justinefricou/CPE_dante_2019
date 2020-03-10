/*
** EPITECH PROJECT, 2020
** display.c
** File description:
** Displays the solution, or a message if there isn't one.
*/

#include "solver.h"

void display_no_solution(void)
{
    printf("no solution found");
}

void display_solution(maze_t maze)
{
    for (int i = 0; i < maze.nb_lines; i++) {
        for (int j = 0; j < maze.nb_cols; j++)
            display_cell(maze.array[i][j]);
        if (i != maze.nb_lines - 1)
            printf("\n");
    }
}

void display_cell(int cell)
{
    if (cell == -3)
        printf("o");
    else if (cell == -1)
        printf("X");
    else
        printf("*");
}