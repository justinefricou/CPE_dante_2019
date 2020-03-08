/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Main function
*/

#include "solver.h"

int main(int argc, char **argv)
{
    maze_t maze = {NULL, 0, 0};

    if (argc != 2)
        return (84);
    if (get_maze(&maze, argv[1]) == 84)
        return (84);


// for (int i = 0; i < maze.nb_lines; i++) {
//     for (int j = 0; j < maze.nb_cols; j++)
//         printf("%i", maze.array[i][j]);
//     printf("\n");
// }

    solve_maze(maze);
    free_matrix(maze.array, maze.nb_lines - 1);
    return (0);
}