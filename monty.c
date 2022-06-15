#include "monty.h"

/**
 * check_args - check the arguments for monty
 * @argc: argument count
 * @argv: argument vector
 * Return: FILE stream
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
	monty.nline = 0;
	monty.stack = NULL;
	monty.arg = NULL;
	monty.line = NULL;
	monty.operate = "stack";
}

/**
 * free_monty - initialize globla variable
 */
void free_monty(void)
{
	while (monty.stack && monty.stack->next)
	{
		monty.stack = monty.stack->next;
		if (monty.stack)
			free(monty.stack->prev);
	}
	if (monty.stack)
		free(monty.stack);
	if (monty.line)
		free(monty.line);
	fclose(monty.fd);
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
	char *opcode;
	void (*f)(stack_t **stack, unsigned int nline);
	const char DELIMITER[4] = " \t\n";

	fd = check_args(argc, argv);
	init_monty(fd);
	while ((flag = getline(&monty.line, &len, fd) != -1))
	{
		monty.nline++;
		opcode = strtok(monty.line, DELIMITER);
		if (opcode && opcode[0] != '#')
		{
			monty.arg = strtok(NULL, DELIMITER);

			f = get_ops(opcode);
			if (!f)
			{
				dprintf(2, "L%d: unknown instruction %s\n", monty.nline, opcode);
				free_monty();
				exit(EXIT_FAILURE);
			}
			f(&monty.stack, monty.nline);
		}
	}

	free_monty();
	return (EXIT_SUCCESS);
}
