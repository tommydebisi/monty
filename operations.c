#include "monty.h"

/**
 * push - adds node to top of stack
 * 
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;


	if (!monty.argv[1] || !_isdigit(monty.argv[1]))
	{
		dprintf(STDERR_FILENO, "L%s: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(monty.argv[1]);
	
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		exit(EXIT_FAILURE);

	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!(*stack))
	{
		*stack = new_node;
		return;
	}

	(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * pall - print all value of list
 *
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *future;

	future = *stack;
	while (future)
	{
		printf("%d\n", future->n);
		future = future->next;
	}
}