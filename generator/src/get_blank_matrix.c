/*
** EPITECH PROJECT, 2020
** get_blank_matrix.c
** File description:
** Allocates memory for an int matrix and fills it with walls.
*/

#include "generator.h"

int get_blank_matrix(maze_t *maze, coord_t dimensions)
{
    maze->nb_lines = dimensions.y;
    maze->nb_cols = dimensions.x;

    maze->matrix = malloc(sizeof(int *) * maze->nb_lines);
    if (maze->matrix == NULL)
        return (84);
    for (int i = 0; i < maze->nb_lines; i++) {
        maze->matrix[i] = malloc(sizeof(int) * (maze->nb_cols));
        if (maze->matrix[i] == NULL) {
            free_matrix(maze->matrix, i - 1);
            return (84);
        }
    }
    fill_matrix_with_walls(maze);
    return (0);
}

void fill_matrix_with_walls(maze_t *maze)
{
    for (int i = 0; i < maze->nb_lines; i++) {
        for (int j = 0; j < maze->nb_cols; j++)
            maze->matrix[i][j] = 0;
    }
}

void free_matrix(int **matrix, int last_line)
{
    for (int i = 0; i <= last_line; i++)
        free(matrix[i]);
    free(matrix);
}