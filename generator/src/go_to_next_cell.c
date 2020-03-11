/*
** EPITECH PROJECT, 2020
** go_to_next_cell.c
** File description:
** Updates the current cell's coords and attributes a distance to the new cell.
*/

#include "generator.h"

int go_to_next_cell(coord_t *current_cell, maze_t *maze)
{
    // TODO : make it random
    coord_t shifts[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    coord_t tested_cell = {0, 0};

    for (int i = 0; i < 4; i++) {
        tested_cell.x = current_cell->x + shifts[i].x;
        tested_cell.y = current_cell->y + shifts[i].y;
        if (cell_can_be_added(tested_cell, maze)) {
            add_cell_to_maze(tested_cell, current_cell, maze);
            return (1);
        }
    }
    return (0);
}

int cell_can_be_added(coord_t tested_cell, maze_t *maze)
{
    coord_t shifts[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    coord_t tested_neighbor = {0, 0};
    int empty_cells_nearby = 0;

    if (!is_in_matrix_bounds(maze, tested_cell))
        return (0);
    if (maze->matrix[tested_cell.x][tested_cell.y] >= 0)
        return (0);
    for (int i = 0; i < 4; i++) {
        tested_neighbor.x = tested_cell.x + shifts[i].x;
        tested_neighbor.y = tested_cell.y + shifts[i].y;
        if (!is_in_matrix_bounds(maze, tested_neighbor))
            continue;
        if (maze->matrix[tested_neighbor.x][tested_neighbor.y] >= 0)
            empty_cells_nearby++;
        if (empty_cells_nearby > 1)
            return (0);
    }
    return (1);
}

void add_cell_to_maze(coord_t new_cell, coord_t *current_cell, maze_t *maze)
{
    int new_distance = 0;

    new_distance = maze->matrix[current_cell->x][current_cell->y] + 1;
    maze->matrix[new_cell.x][new_cell.y] = new_distance;
    current_cell->x = new_cell.x;
    current_cell->y = new_cell.y;
}