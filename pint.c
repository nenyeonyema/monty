#include "monty.h"

/**
 * pint_element - a function that prints the value at the top of the stack
 * @head: head of the linked list
 * @count_line: line number
 * Return: void
 */
void pint_element(stack_t **head, unsigned int count_line)
{
	(void)count_line;

	if (*head == NULL)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", count_line);
		_free_vg();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
