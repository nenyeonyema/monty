#include "monty.h"

/**
 * mod_element - a function that computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @head: head of the linked list
 * @count_line: the number of lines
 * Return: void
 */
void mod_element(stack_t **head, unsigned int count_line)
{
	int j = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, j++)
		;

	if (j < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", count_line);
		_free_vg();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", count_line);
		_free_vg();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n %= (*head)->n;
	pop_element(head, count_line);
}
