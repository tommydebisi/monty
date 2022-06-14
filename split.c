#include "monty.h"

/**
 * split - tokenizes a line into an array
 */
char** split(char *line)
{
	char *argv[2] = {NULL, NULL};
	int index = 0;
	char* token;
	const char DELIMITER[4] = " \t\n";
	
	token = strtok(line, DELIMITER);

	// Checks for delimiter
	while (token) {
		argv[index++] = token;
		token = strtok(NULL, DELIMITER);
	}

	return argv;
}