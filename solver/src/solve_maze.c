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
            //save_path(maze, pos); // TODO
            //display_solution(maze); // TODO
            go_on = 0;
        } else if (!go_to_cell(maze, &pos, -2)) {
            if (maze.array[pos.x][pos.y] == 0) {
                display_no_solution();
                go_on = 0;
            } else
                go_to_cell(maze, &pos, current_distance - 1);

        }

        /*for (int i = 0; i < maze.nb_lines; i++) {
            for (int j = 0; j < maze.nb_cols; j++) {
                printf(" ");
                if (maze.array[i][j] < 10)
                    printf(" ");
                if (maze.array[i][j] == -2)
                    printf("*");
                else if (maze.array[i][j] == -1)
                    printf("X");
                else
                    printf("%i", maze.array[i][j]);
                printf(" ");
            }
            printf("\n");
        }
        printf("\n");*/
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
printf("current distance = %i\n", *current_distance);
    if (*cell == -2)
        *cell = *current_distance + 1;
    *current_distance = *cell;
}