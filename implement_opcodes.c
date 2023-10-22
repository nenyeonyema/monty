#include "monty.h"

/**
 * implement - a function that selects the correct opcode to implement
 * @opc: value of the opcode
 * Return: pointer of the executed opcode
 */
void (*implement(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push_element},
		{"pall", pall_element},
		{"pint", pint_element},
		{"pop", pop_element},
		{"swap", swap_element},
		{"add", add_element},
		{"nop", nop_},
		{"sub", sub_element},
		{"div", div_element},
		{"mul", mul_element},
		{"mod", mod_element},
		{"pchar", pchar_},
		{"pstr", pstr_},
		{"rotl", rotl_},
		{"rotr", rotr_},
		{"stack", stack_},
		{"queue", queue_},
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
