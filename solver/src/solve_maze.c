/*
** EPITECH PROJECT, 2020
** solve_maze.c
** File description:
** Finds the right path through the maze if any, and saves it in the matrix.
*/

#include "solver.h"

int solve_maze(maze_t maze)
{
    coord_t pos = {0, 0};
    int current_distance = 0;
    int go_on = 1;

    if (is_start_or_end_blocked(maze)) {
        display_no_solution();
        return (0);
    }
    maze.array[0][0] = 0;
    while (go_on) {
        attribute_distance(&(maze.array[pos.x][pos.y]), &current_distance);
        if (pos.x == maze.nb_lines - 1 && pos.y == maze.nb_cols - 1) {
            save_path(&maze, pos);
            display_solution(maze);
            go_on = 0;
        } else if (!go_to_cell(maze, &pos, -2))
            go_back(maze, &pos, current_distance, &go_on);
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

void attribute_distance(int *cell, int *current_distance)
{
    if (*cell == -2)
        *cell = *current_distance + 1;
    *current_distance = *cell;
}

void go_back(maze_t maze, coord_t *pos, int current_distance, int *go_on)
{
    if (pos->x == 0 && pos->y == 0) {
        display_no_solution();
        *go_on = 0;
    } else
        go_to_cell(maze, pos, current_distance - 1);
}

void save_path(maze_t *maze, coord_t pos)
{
    int current_distance = 0;

    while (pos.x != 0 || pos.y != 0) {
        current_distance = maze->array[pos.x][pos.y];
        maze->array[pos.x][pos.y] = -3;
        go_to_cell(*maze, &pos, current_distance - 1);
    }
}