#include "monty.h"
/***
* Compares instruction/opcodes and runs its functions
*/void the_func(stack_t **stack, unsigned int line_number, char *opcode)
{
	int i = 0;

	instruction_t func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (func[i].opcode != NULL)
	{
		if (strcmp(opcode, func[i].opcode) == 0)
		{
			func[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
