/*
** EPITECH PROJECT, 2020
** generator.h
** File description:
** generator : header
*/

#ifndef DEF_GENERATOR
#define DEF_GENERATOR

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct coord {
    int x;
    int y;
} coord_t;

typedef struct maze {
    int nb_lines;
    int nb_cols;
    int **matrix;
} maze_t;

// error_detection.c
int detect_errors(int argc, char **argv);
int my_is_int(char *str);

// get_dimensions.c
int get_dimensions(char **args, coord_t *dimensions);
int my_get_nbr(char *str);

// get_maze.c
int get_maze(char **maze_as_string, coord_t dimensions, int perfect);
int get_maze_as_string(char **string, maze_t maze);

// get_blank_matrix.c
int get_blank_matrix(maze_t *maze, coord_t dimensions);
void fill_matrix_with_walls(maze_t *maze);
void free_matrix(int **matrix, int last_line);

// maze_generation.c

#endif // DEF_GENERATOR