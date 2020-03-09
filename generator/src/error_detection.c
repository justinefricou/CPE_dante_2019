/*
** EPITECH PROJECT, 2020
** error_detection.c
** File description:
** Detects errors in the arguments
*/

#include "generator.h"

int detect_errors(int argc, char **argv)
{
    if (!(argc == 3 || (argc == 4 && strcmp(argv[3], "perfect") == 0)))
        return (1);
    if (!my_is_int(argv[1]) || !my_is_int(argv[2]))
        return (1);
    return (0);
}

int my_is_int(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    for ( ; str[i] != 0; i++) {
        if (str[i] < '0' || '9' < str[i])
            return (0);
    }
    return (1);
}