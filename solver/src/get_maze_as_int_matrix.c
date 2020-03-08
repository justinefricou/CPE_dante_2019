/*
** EPITECH PROJECT, 2020
** get_maze_as_int_matrix.c
** File description:
** Gets the maze as an int matrix from a string
*/

#include "solver.h"

int get_maze_as_int_matrix(maze_t *maze, char *str)
{
    maze->nb_lines = get_nb_lines(str);
    maze->array = malloc(sizeof(int *) * maze->nb_lines);
    if (maze->array == NULL)
        return (84);
    maze->nb_cols = get_nb_cols(str);
    for (int i = 0; i < maze->nb_lines; i++) {
        if (maze->nb_cols != get_nb_cols(str) || is_badly_formatted_line(str)) {
            free_matrix(maze->array, i - 1);
            return (84);
        }
        if (line_to_int_array(&(maze->array[i]), str, maze->nb_cols) == 84) {
            free_matrix(maze->array, i - 1);
            return (84);
        }
        str += maze->nb_cols + 1;
    }
    return (0);
}

int get_nb_lines(char *str)
{
    int nb_lines = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '\n')
            nb_lines++;
    }
    return (nb_lines + 1);
}

int get_nb_cols(char *str)
{
    int nb_cols = 0;

    for (; str[nb_cols] != '\n' && str[nb_cols] != 0; nb_cols++);
    return (nb_cols);
}

int line_to_int_array(int **array, char *str, int length)
{
    *array = malloc(sizeof(int) * length);
    if (*array == NULL)
        return (84);
    for (int i = 0; i < length; i++)
        (*array)[i] = (str[i] == 'X') - 2;
    return (0);
}

void free_matrix(int **matrix, int last_line)
{
    for (int i = 0; i <= last_line; i++)
        free(matrix[i]);
    free(matrix);
}