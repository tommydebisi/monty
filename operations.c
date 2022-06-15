#include "monty.h"

/**
 * push - adds node to top of stack
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void push(stack_t **stack, unsigned int nline)
{
	stack_t *new_node, *future = *stack;
	int value;


	if (!monty.arg || !_isdigit(monty.arg))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", nline);
		exit(EXIT_FAILURE);
	}
	value = atoi(monty.arg);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		exit(EXIT_FAILURE);

	new_node->n = value, new_node->next = NULL, new_node->prev = NULL;

	if (!(*stack))
	{
		*stack = new_node;
		return;
	}

	if (strcmp("stack", monty.operate) == 0)	/* for (LIFO) */
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		*stack = new_node;
		return;
	}

	if (!(*stack)->next)	/* for queue (FIFO) */
		future->next = new_node, new_node->prev = future;
	else
	{
		while (future->next)
			future = future->next;

		future->next = new_node, new_node->prev = future;
	}
}

/**
 * pall - print all value of list
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *future;
	(void)nline;

	future = *stack;
	while (future)
	{
		printf("%d\n", future->n);
		future = future->next;
	}
}

/**
 * pint - prints the value at the top of stack
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void pint(stack_t **stack, unsigned int nline)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void pop(stack_t **stack, unsigned int nline)
{
	stack_t *future;

	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", nline);
		exit(EXIT_FAILURE);
	}

	future = *stack;
	future = future->next;
	free(*stack);
	if (future)
		future->prev = NULL;
	*stack = future;
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void swap(stack_t **stack, unsigned int nline)
{
	stack_t *future;

	future = *stack;
	if (!future || !future->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	future->prev = future->next;
	future->next->prev = NULL;
	if (future->next->next)
		future->next->next->prev = future;
	future->next = future->next->next;
	future->prev->next = future;
	*stack = future->prev;
}
