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
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
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
	(void)line_number;

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
 * @line_number: line  currently on
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *future;
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
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
 * @line_number: line  currently on
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *future;

	future = *stack;
	if (!future || !future->next || !future->next->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	future->prev = future->next;
	future->next->prev = NULL;
	future->next->next->prev = future;
	future->next = future->next->next;
	future->prev->next = future;
	*stack = future->prev;
}