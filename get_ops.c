#include "monty.h"

void (*get_ops(char *opcode))(stack_t **stack, unsigned int line_number)
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
		{ NULL, NULL }
	};

	for (i = 0; op_list[i].opcode; i++)
	{
		if (strcmp(opcode, op_list[i].opcode) == 0)
			return (op_list[i].f);
	}
	return (NULL);
}