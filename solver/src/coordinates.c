/*
** EPITECH PROJECT, 2020
** coordinates.c
** File description:
** Tools to navigate in the maze : go to previous or unvisited cells
*/

#include "solver.h"

int go_to_cell(maze_t maze, coord_t *pos, int wanted_nb)
{
    coord_t shifts_go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    coord_t shifts_back[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    coord_t *shifts = NULL;

    shifts = (wanted_nb == -2) ? shifts_go : shifts_back;
    for (int i = 0; i < 4; i++) {
        if (update_coords(maze, pos, shifts[i], wanted_nb))
            return (1);
    }
    return (0);
}

int update_coords(maze_t maze, coord_t *pos, coord_t shift, int wanted_nb)
{
    int cell = 0;

    if (pos->x + shift.x < 0 || pos->y + shift.y < 0)
        return (0);
    if (pos->x + shift.x >= maze.nb_lines || pos->y + shift.y >= maze.nb_cols)
        return (0);
    cell = maze.array[pos->x + shift.x][pos->y + shift.y];
    if (cell == wanted_nb || (cell <= wanted_nb && cell >= 0)) {
        pos->x += shift.x;
        pos->y += shift.y;
        return (1);
    }
    return (0);
}