#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void mod(stack_t **stack, unsigned int nline)
{
	stack_t *future;

	future = *stack;
	if (!future || !future->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	if (future->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero", nline);
		exit(EXIT_FAILURE);
	}

	future->next->n %= future->n;	/* update value of next */
	future = future->next;
	future->prev = NULL;
	free(*stack);
	*stack = future;
}
