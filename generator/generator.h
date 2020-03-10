/*
** EPITECH PROJECT, 2020
** generator.h
** File description:
** generator : header
*/

#ifndef DEF_GENERATOR
#define DEF_GENERATOR

#include <string.h>
#include <stdio.h>

typedef struct coord {
    int x;
    int y;
} coord_t;

// error_detection.c
int detect_errors(int argc, char **argv);
int my_is_int(char *str);

// get_dimensions.c
int get_dimensions(char **args, coord_t *dimensions);
int my_get_nbr(char *str);

// maze_generation.c

#endif // DEF_GENERATOR