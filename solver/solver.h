/*
** EPITECH PROJECT, 2020
** solver.h
** File description:
** solver : header
*/

#ifndef DEF_SOLVER
#define DEF_SOLVER

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct maze {
    int **array;
    int nb_lines;
    int nb_cols;
} maze_t;

typedef struct coord {
    int x;
    int y;
} coord_t;

// get_maze.c
int get_maze(maze_t *maze, char *filepath);
int get_maze_as_string(char **maze_as_string, char *filepath);
int copy_file_in_string(int file_descr, char *maze, int file_length);

// get_maze_as_int_matrix.c
int get_maze_as_int_matrix(maze_t *maze, char *str);
int get_nb_lines(char *str);
int get_nb_cols(char *str);
int line_to_int_array(int **array, char *str, int length);
void free_matrix(int **matrix, int last_line);

// error_detection.c
int is_badly_formatted_line(char *str);

// solve_maze.c
int solve_maze(maze_t maze);
int is_start_or_end_blocked(maze_t maze);
void attribute_distance(int *cell, int *current_distance);

// coordinates.c
int go_to_cell(maze_t maze, coord_t *pos, int wanted_nb);
int update_coords(maze_t maze, coord_t *pos, coord_t shift, int wanted);

// display.c
void display_no_solution(void);
void display_solution(maze_t maze);
void display_cell(int cell);
void my_put_str(char *str, int file_descr);

#endif // DEF_SOLVER