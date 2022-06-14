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
	monty.stack = NULL;
	monty.argv = NULL;
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
	char *line, *opcode, *arg;
	void (*f)(stack_t **stack, unsigned int line_number);
	const char DELIMITER[4] = " \t\n";

	fd = check_args(argc, argv);
	init_monty(fd);
	while ((flag = getline(&line, &len, fd) != -1))
	{
		opcode = strtok(line, DELIMITER);
		if (!opcode) {
			dprintf(STDERR_FILENO, "No opcode");
			exit(EXIT_FAILURE);
		}
		printf("opcode: [%s]", opcode);
		arg = strtok(NULL, DELIMITER);
		if (arg)
			printf(" arg: [%s]", arg);
		printf("\n");
		// f = get_ops()
		// f(); // if f is not NULL
	}

	return (EXIT_SUCCESS);
}