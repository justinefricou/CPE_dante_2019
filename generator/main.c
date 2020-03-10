/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Main function
*/

#include "generator.h"

int main(int argc, char **argv)
{
    char *maze = NULL;
    coord_t dimensions = {0, 0};

    if (detect_errors(argc, argv))
        return (84);
    if (get_dimensions(&(argv[1]), &dimensions) == 84)
        return (84);
    if (generate_maze(&maze, dimensions, (argc == 4)) == 84)
        return (84);
    printf("%s", maze);
    return (0);
}