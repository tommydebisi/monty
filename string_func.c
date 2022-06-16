#include "monty.h"
/**
 * _isdigit - prints the return value is digit or not
 * @str: string to check
 * Return: 1 if it's digit and 0 otherwise
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
	}
	return (1);
}
