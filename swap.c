#include "monty.h"

/**
 * swap_element - a function that swaps the top two elements of the stack
 * @doubly: head of the linked list
 * @count_line: the number of lines
 * Return: void
 */
void swap_element(stack_t **head, unsigned int count_line)
{
	int n = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, n++)
		;

	if (n < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", count_line);
		_free_vg();
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	*head = (*head)->next;
	ptr->next = (*head)->next;
	ptr->prev = *head;
	(*head)->next = ptr;
	(*head)->prev = NULL;
}
