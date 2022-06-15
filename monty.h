#ifndef _MONTY_H_
#define _MONTY_H_

/* For dprintf and getline support */
#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE

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
		void (*f)(stack_t **stack, unsigned int nline);
} instruction_t;

/**
 * struct monty_s - global variable for monty interpreter
 * @stack: stack
 * @nline: line number
 * @arg: argument for the instruction
 * @operate: operation to perform (Stack/Queue)
 * @fd: file descriptor
 * @line: line of
 */
typedef struct monty_s
{
	stack_t *stack;
	unsigned int nline;
	char *arg;
	char *operate;
	FILE *fd;
	char *line;
} monty_t;

extern monty_t monty;
monty_t monty;

void free_monty(void);


/* Operations */
void push(stack_t **stack, unsigned int nline);
void pall(stack_t **stack, unsigned int nline);
void pint(stack_t **stack, unsigned int nline);
void pop(stack_t **stack, unsigned int nline);
void swap(stack_t **stack, unsigned int nline);
void add(stack_t **stack, unsigned int nline);
void nop(stack_t **stack, unsigned int nline);
void sub(stack_t **stack, unsigned int nline);
void o_div(stack_t **stack, unsigned int nline);
void mul(stack_t **stack, unsigned int nline);
void mod(stack_t **stack, unsigned int nline);
void pchar(stack_t **stack, unsigned int nline);
void pstr(stack_t **stack, unsigned int nline);
void rotl(stack_t **stack, unsigned int nline);
void rotr(stack_t **stack, unsigned int nline);
void o_stack(stack_t **stack, unsigned int nline);
void o_queue(stack_t **stack, unsigned int nline);

void (*get_ops(char *opcode))(stack_t **stack, unsigned int nline);

/* string functions */
int _isdigit(char *str);

#endif /* _MONTY_H_ */
