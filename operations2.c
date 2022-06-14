#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *future;

	future = *stack;
	if (!future || !future->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	future->next->n += future->n;	/* update value of next */
	future = future->next;
	future->prev = NULL;
	free(*stack);
	*stack = future;
}

/**
 * nop - doesn't do anything
 *
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
