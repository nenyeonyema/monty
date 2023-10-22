#include "monty.h"

/**
 * sub_element - a function that subtracts the top element
 * to the second top element of the stack
 * @head: head of the linked list
 * @count_line: the number of lines
 * Return: void
 */
void sub_element(stack_t **head, unsigned int count_line)
{
	int j = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, j++)
		;

	if (j < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", count_line);
		_free_vg();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n -= (*head)->n;
	pop_element(head, count_line);
}
