/*
** EPITECH PROJECT, 2020
** maze_generation.c
** File description:
** Turns a matrix's walls into empty cells to make a maze.
*/

#include "generator.h"

void generate_maze(maze_t *maze, int perfect)
{
    coord_t current_cell = {0, 0};
    int go_on = 1;

    maze->matrix[0][0] = 0;
    for (int i = 0; i < maze->nb_lines; i++)
        maze->matrix[i][maze->nb_cols - 1] = 0;
    while (go_on) {
        if (go_to_next_cell(&current_cell, maze))
            continue;
        else if (current_cell.x == 0 && current_cell.y == 0) {
            link_maze_to_end(maze);
            make_maze_imperfect(maze, perfect);
            go_on = 0;
        } else
            go_to_previous_cell(&current_cell, maze);
    }
}

void go_to_previous_cell(coord_t *current_cell, maze_t *maze)
{
    coord_t shifts[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    coord_t tested_cell = {0, 0};
    int current_dist = 0;

    current_dist = maze->matrix[current_cell->x][current_cell->y];
    for (int i = 0; i < 4; i++) {
        tested_cell.x = current_cell->x + shifts[i].x;
        tested_cell.y = current_cell->y + shifts[i].y;
        if (!is_in_matrix_bounds(maze, tested_cell))
            continue;
        if (maze->matrix[tested_cell.x][tested_cell.y] == current_dist - 1) {
            current_cell->x = tested_cell.x;
            current_cell->y = tested_cell.y;
            return;
        }
    }
}

int is_in_matrix_bounds(maze_t *maze, coord_t cell)
{
    if (cell.x < 0 || cell.y < 0)
        return (0);
    if (cell.x >= maze->nb_lines || cell.y >= maze->nb_cols)
        return (0);
    return (1);
}