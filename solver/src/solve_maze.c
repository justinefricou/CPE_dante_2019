/*
** EPITECH PROJECT, 2020
** solve_maze.c
** File description:
** Finds the right path through the maze if any, and saves it in the matrix.
*/

#include "solver.h"

int solve_maze(maze_t maze)
{
    int line = 0;
    int col = 0;
    int go_on = 1;

    if (is_start_or_end_blocked(maze)) {
        display_no_solution();
        return (0);
    }
    // while (go_on) {

    // }
    return (0);
}

int is_start_or_end_blocked(maze_t maze)
{
    if (maze.array[0][0] != -2)
        return (1);
    if (maze.array[maze.nb_lines - 1][maze.nb_cols - 1] != -2)
        return (1);
    return (0);
}