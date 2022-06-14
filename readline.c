#include "monty.h"

/**
 * readline - reads the each line of file
 * 
 * @fd: file descriptor of file to be read
 * Return: 1 if no error else -1 if error
 */
int readline(int fd)
{
    int get_check;
    ssize_t bufzize = 0;
    char *buf = NULL;

    while (1)
    {
        get_check = getline(&buf, &bufzize, fd);
        if (get_check == -1)
            break;
    }
    return (1);
}