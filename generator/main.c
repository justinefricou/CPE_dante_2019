/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Main function
*/

#include "generator.h"

int main(int argc, char **argv)
{
    if (detect_errors(argc, argv))
        return (84);
    return (0);
}