#include "monty.h"

monty_t monty;

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
	monty.line_number = 0;
	monty.stack = NULL;
	monty.arg = NULL;
}

/**
 * free_monty - initialize globla variable
 */
void free_monty()
{
	while (monty.stack && monty.stack->next)
	{
		monty.stack = monty.stack->next;
		if (monty.stack)
			free(monty.stack->prev);
	}
	if (monty.stack)
		free(monty.stack);
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
	char *line, *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
	const char DELIMITER[4] = " \t\n";

	fd = check_args(argc, argv);
	init_monty(fd);
	while ((flag = getline(&line, &len, fd) != -1))
	{
		monty.line_number++;
		opcode = strtok(line, DELIMITER);
		if (!opcode)
		{
			dprintf(STDERR_FILENO, "No opcode");
			exit(EXIT_FAILURE);
		}
		if (opcode[0] != '#')
		{
			monty.arg = strtok(NULL, DELIMITER);
		
			f = get_ops(opcode);
			if (!f)
			{
				dprintf(STDERR_FILENO, "L%d: unknown instruction %s", monty.line_number, opcode);
				exit(EXIT_FAILURE);
			}
			f(&monty.stack, monty.line_number);
		}
	}

	free(line);
	free_monty();
	return (EXIT_SUCCESS);
}
