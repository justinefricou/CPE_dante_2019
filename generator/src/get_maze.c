/*
** EPITECH PROJECT, 2020
** get_maze.c
** File description:
** Generates a maze, perfect or not depending on the arguments.
*/

#include "generator.h"

int get_maze(char **maze_as_string, coord_t dimensions, int perfect)
{
    maze_t maze = {0, 0, NULL};

    if (get_blank_matrix(&maze, dimensions) == 84)
        return (84);
    generate_maze(&maze, perfect);
    if (get_maze_as_string(maze_as_string, maze) == 84) {
        free_matrix(maze.matrix, maze.nb_lines - 1);
        return (84);
    }
    free_matrix(maze.matrix, maze.nb_lines - 1);
    return (0);
}

int get_maze_as_string(char **string, maze_t maze)
{
    int length = 0;
    char *copy_pointer = NULL;

    length = maze.nb_lines * (maze.nb_cols + 1);
    *string = malloc(sizeof(char) * (length + 1));
    if (*string == NULL)
        return (84);
    copy_pointer = *string;
    for (int i = 0; i < maze.nb_lines; i++) {
        for (int j = 0; j < maze.nb_cols; j++) {
            *copy_pointer = (maze.matrix[i][j] == -1) ? 'X' : '*';
            copy_pointer++;
        }
        if (i != maze.nb_lines - 1) {
            *copy_pointer = '\n';
            copy_pointer++;
        }
    }
    *copy_pointer = 0;
    return (0);
}