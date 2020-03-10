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

int display_solution(maze_t maze)
{
    char *solution = NULL;

    if (get_solution(&solution, maze) == 84)
        return (84);
    printf("%s", solution);
    return (0);
}

int get_solution(char **solution, maze_t maze)
{
    int length = 0;
    char *copy_pointer = NULL;

    length = maze.nb_lines * (maze.nb_cols + 1);
    *solution = malloc(sizeof(char) * (length + 1));
    if (*solution == NULL)
        return (84);
    copy_pointer = *solution;
    for (int i = 0; i < maze.nb_lines; i++) {
        for (int j = 0; j < maze.nb_cols; j++)
            add_cell_to_solution(maze.array[i][j], &copy_pointer);
        if (i != maze.nb_lines - 1) {
            *copy_pointer = '\n';
            copy_pointer++;
        }
    }
    *copy_pointer = 0;
    return (0);
}

void add_cell_to_solution(int cell, char **solution)
{
    if (cell == -3)
        **solution = 'o';
    else if (cell == -1)
        **solution = 'X';
    else
        **solution = '*';
    (*solution)++;
}