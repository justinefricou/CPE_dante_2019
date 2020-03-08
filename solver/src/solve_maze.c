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
    int last_distance = 0;
    int go_on = 1;

    if (is_start_or_end_blocked(maze)) {
        display_no_solution();
        return (0);
    }
    maze.array[0][0] = 0;
    while (go_on) {
        attribute_distance(&(maze[line][col]), last_distance);
        if (line == maze.nb_lines - 1 && col == maze.nb_cols - 1) {
            save_path(maze, col, line); // TODO
            display_solution(maze); // TODO
            go_on = 0;
        } else if (!get_unvisited_cell_coords(maze, &line, &col))
            get_previous_cell(maze, &line, &col); // TODO
        // TODO : if while going back, we don't find any unvisited cell
        // stop and display "no solution found"
    }
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

void attribute_distance(int *cell, int last_distance)
{
    if (*cell == -1)
        *cell = last_distance + 1;
}

int get_unvisited_cell_coords(maze_t maze, int *line, int *col)
{
    int go_on = 1;

    for (int i = -1; i <= 1 && go_on; i++) {
        for (int j = -1; j <= 1 && go_on; j++)
            go_on = !update_coords(maze.array[*line + i][*col + j], line, col);
    }
    if (go_on)
        return (0);
    return (1);
}

int update_coords(int cell, int *line, int *col)
{
    if (cell == -1) {
        (*line) += i;
        (*col) += j;
        return (1);
    }
    return (0);
}