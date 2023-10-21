#include "monty.h"

/**
 * implement_opcodes - a function that selects the correct opcode to implement
 * @opc: value of the opcode
 * Return: pointer of the executed opcode
 */
void (*implement(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push_element},
		{"pall", pall_element},
		{NULL, NULL}
	};

	int n;

	for (n = 0; instruct[n].opcode; n++)
	{
		if (_strcmp(instruct[n].opcode, opc) == 0)
			break;
	}
	return (instruct[n].f);

	return (0);
}
