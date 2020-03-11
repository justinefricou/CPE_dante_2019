/*
** EPITECH PROJECT, 2020
** finish_maze.c
** File description:
** Links the maze to the ending cell and makes it imperfect if needed.
*/

#include "generator.h"

void link_maze_to_end(maze_t *maze)
{
    coord_t tested_cell = {0, maze->nb_cols - 2};

    if (maze->nb_cols <= 2)
        return;
    for (int i = 0; i < maze->nb_lines; i++) {
        tested_cell.x = i;
        if (can_be_linking_cell(tested_cell, maze)) {
            maze->matrix[tested_cell.x][tested_cell.y] = 0;
            return;
        }
    }
}

int can_be_linking_cell(coord_t cell, maze_t *maze)
{
    coord_t shifts[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    coord_t tested_neighbor = {0, 0};
    int empty_cells_nearby = 0;

    if (!is_in_matrix_bounds(maze, cell))
        return (0);
    if (maze->matrix[cell.x][cell.y] >= 0)
        return (0);
    for (int i = 0; i < 4; i++) {
        tested_neighbor.x = cell.x + shifts[i].x;
        tested_neighbor.y = cell.y + shifts[i].y;
        if (!is_in_matrix_bounds(maze, tested_neighbor))
            continue;
        if (maze->matrix[tested_neighbor.x][tested_neighbor.y] >= 0)
            empty_cells_nearby++;
    }
    if (empty_cells_nearby <= 1)
        return (0);
    return (1);
}

void make_maze_imperfect(maze_t *maze, int perfect)
{
    // TODO
}