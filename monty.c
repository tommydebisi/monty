#include "monty.h"

monty_t monty;

/**
 * check_args - check the arguments for monty
 * @argc: argument count
 * @argv: argument vector
 */
FILE *check_args(int argc, char *argv[])
{
	FILE *fd;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (!fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * init_monty - initialize globla variable
 * @fd: File descriptor
 */
void init_monty(FILE *fd)
{
	monty.fd = fd;
	monty.line_number = 0;
	monty.top = NULL;
}

/**
 * main - the main operations take place
 * 
 * @argc: number of argument
 * @argv: elements of argument
 * Return: 0 if succesful else another number if not
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	ssize_t flag;
	size_t len = 0;
	char *line;

	fd = check_args(argc, argv);
	init_monty(fd);
	while ((flag = getline(&line, &len, fd) != -1))
	{
		// handle line
	}
}