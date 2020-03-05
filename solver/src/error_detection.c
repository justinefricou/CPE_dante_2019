/*
** EPITECH PROJECT, 2020
** error_detection.c
** File description:
** Solver : detects if a there are formatting errors in a line
*/

#include "solver.h"

int is_badly_formatted_line(char *str)
{
    for (int i = 0; str[i] != '\n' && str[i] != 0; i++) {
        if (str[i] != 'X' && str[i] != '*')
            return (1);
    }
    return (0);
}