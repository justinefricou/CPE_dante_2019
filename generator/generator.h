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
#include <time.h>

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
void generate_maze(maze_t *maze, int perfect);
void go_to_previous_cell(coord_t *current_cell, maze_t *maze);
int is_in_matrix_bounds(maze_t *maze, coord_t cell);

// go_to_next_cell.c
int go_to_next_cell(coord_t *current_cell, maze_t *maze);
int cell_can_be_added(coord_t tested_cell, maze_t *maze);
void add_cell_to_maze(coord_t new_cell, coord_t *current_cell, maze_t *maze);

// finish_maze.c
void link_maze_to_end(maze_t *maze);
int can_be_linking_cell(coord_t cell, maze_t *maze);
void make_maze_imperfect(maze_t *maze, int perfect);
void empty_cell_if_linking(coord_t cell, maze_t *maze, int *go_on);

#endif // DEF_GENERATOR