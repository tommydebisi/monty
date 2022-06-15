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
		dprintf(STDERR_FILENO, "L%u: division by zero\n", nline);
		exit(EXIT_FAILURE);
	}

	future->next->n %= future->n;	/* update value of next */
	future = future->next;
	future->prev = NULL;
	free(*stack);
	*stack = future;
}

/**
 * pchar - prints the char at the top of the stack
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void pchar(stack_t **stack, unsigned int nline)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 255)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", nline);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void pstr(stack_t **stack, unsigned int nline)
{
	int count;
	stack_t *current;

	(void) nline;

	current = *stack;
	for (count = 0; current && (current->n > 0 && current->n <= 255); count++)
		current = current->next;

	current = *stack;
	for (; count > 0; count--)
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void rotl(stack_t **stack, unsigned int nline)
{
	stack_t *current, *head;

	(void) nline;

	current = head = *stack;
	while (current && current->next)
		current = current->next;

	current->next = head; /* Make linked list a cycle */
	*stack = head->next; /* Make stack top be second node */
	head->next = NULL;
	head->prev = current;
}

/**
 * rotr - rotates the stack to the top
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void rotr(stack_t **stack, unsigned int nline)
{
	stack_t *current, *head;

	(void) nline;

	current = head = *stack;
	while (current && current->next)
		current = current->next;

	current->next = head; /* Make linked list a cycle */
	head->prev = current;
	current->prev->next = NULL;
	current->prev = NULL;
	*stack = current;
}
