/*
** EPITECH PROJECT, 2020
** get_maze.c
** File description:
** Gets the maze from the file passed as parameter
*/

#include "solver.h"

int get_maze(maze_t *maze, char *filepath)
{
    char *maze_as_string = NULL;

    if (get_maze_as_string(&maze_as_string, filepath) == 84)
        return (84);
    if (get_maze_as_int_matrix(maze, maze_as_string) == 84) {
        free(maze_as_string);
        return (84);
    }
    free(maze_as_string);
    return (0);
}

int get_maze_as_string(char **maze_as_string, char *filepath)
{
    int file_descr = 0;
    struct stat buffer;
    int length = 0;

    file_descr = open(filepath, O_RDONLY);
    if (file_descr == -1)
        return (84);
    if (fstat(file_descr, &buffer) == -1)
        return (84);
    length = buffer.st_size;
    *maze_as_string = malloc(sizeof(char) * (length + 1));
    if (*maze_as_string == NULL)
        return (84);
    if (copy_file_in_string(file_descr, *maze_as_string, length) == 84) {
        free(*maze_as_string);
        return (84);
    }
    close(file_descr);
    return (0);
}

int copy_file_in_string(int file_descr, char *maze, int file_length)
{
    int size_of_read = 0;

    size_of_read = read(file_descr, maze, file_length);
    if (size_of_read != file_length)
        return (84);
    maze[file_length] = 0;
    return (0);
}