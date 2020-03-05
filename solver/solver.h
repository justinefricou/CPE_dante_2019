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

#endif // DEF_SOLVER