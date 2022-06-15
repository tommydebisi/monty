#include "monty.h"

/**
 * get_ops - function pointer for opcode
 *
 * @opcode: string containing instruction
 * Return: function for the opcode
 */
void (*get_ops(char *opcode))(stack_t **stack, unsigned int nline)
{
	unsigned int i;
	instruction_t op_list[] = {
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "swap", swap },
		{ "add", add },
		{ "nop", nop },
		{ "pop", pop },
		{ "sub", sub },
		{ "div", o_div },
		{ "mul", mul },
		{ "mod", mod },
		{ "pchar", pchar },
		{ "pstr", pstr },
		{ "rotl", rotl },
		{ "rotr", rotr },
		{ "stack", o_stack },
		{ "queue", o_queue },
		{ NULL, NULL }
	};

	for (i = 0; op_list[i].opcode; i++)
	{
		if (strcmp(opcode, op_list[i].opcode) == 0)
			return (op_list[i].f);
	}
	return (NULL);
}
