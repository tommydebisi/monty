#include "monty.h"

/**
 * o_stack - sets the format of the data to a stack (LIFO)
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void o_stack(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;

	monty.operate = "stack";
}

/**
 * o_queue - sets the format of the data to a queque (FIFO)
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void o_queue(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;

	monty.operate = "queue";
}
