/*
** EPITECH PROJECT, 2020
** get_dimensions.c
** File description:
** Gets the dimensions of the maze and checks their value.
*/

#include "generator.h"

int get_dimensions(char **args, coord_t *dimensions)
{
    dimensions->x = my_get_nbr(args[0]);
    dimensions->y = my_get_nbr(args[1]);
    if (dimensions->x <= 0 || dimensions->y <= 0)
        return (84);
    return (0);
}

int my_get_nbr(char *str)
{
    int nbr = 0;
    int i = 0;

    for (; str[i] == '-' || str[i] == '+' || str[i] == '0'; i++);
    for (; str[i] != 0; i++)
        nbr = nbr * 10 + (str[i] - 48);
    if (str[0] == '-')
        nbr = nbr * (-1);
    return (nbr);
}