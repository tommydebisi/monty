#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void add(stack_t **stack, unsigned int nline)
{
	stack_t *future;

	future = *stack;
	if (!future || !future->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", nline);
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
 * @nline: line  currently on
 */
void nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}

/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack.
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void sub(stack_t **stack, unsigned int nline)
{
	stack_t *future;

	future = *stack;
	if (!future || !future->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	future->next->n -= future->n;	/* update value of next */
	future = future->next;
	future->prev = NULL;
	free(*stack);
	*stack = future;
}

/**
 * o_div - divides the second top element of the stack
 * by the top element of the stack.
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void o_div(stack_t **stack, unsigned int nline)
{
	stack_t *future;

	future = *stack;
	if (!future || !future->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	if (future->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", nline);
		exit(EXIT_FAILURE);
	}

	future->next->n /= future->n;	/* update value of next */
	future = future->next;
	future->prev = NULL;
	free(*stack);
	*stack = future;
}

/**
 * mul -  multiplies the second top element of the stack
 * with the top element of the stack.
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void mul(stack_t **stack, unsigned int nline)
{
	stack_t *future;

	future = *stack;
	if (!future || !future->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	future->next->n *= future->n;	/* update value of next */
	future = future->next;
	future->prev = NULL;
	free(*stack);
	*stack = future;
}
