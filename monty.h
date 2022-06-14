#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <syscall.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_s - global variable for monty interpreter
 * @stack: stack
 * @line_number: line number
 * @ac: tokenized value
 * @fd: file descriptor
 */
typedef struct monty_s
{
	stack_t *stack;
	unsigned int line_number;
	char **argv;
	FILE *fd;
} monty_t;

extern monty_t monty;

/* Operations */
void push(stack_t **stack, unsigned int line_number);
int _isdigit(char *str);

int readline(fd);
#endif /* _MONTY_H_ */
