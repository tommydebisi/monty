#include "monty.h"

/**
 * main - the main operations take place
 * 
 * @argc: number of argument
 * @argv: elements of argument
 * Return: 0 if succesful else another number if not
 */
int main(int argc, char *argv[])
{
    int fd, read_check;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    read_check = readline(fd);
}