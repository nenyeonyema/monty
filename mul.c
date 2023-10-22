#include "monty.h"

/**
 * mul_element - a function that multiplies the second top element
 * of the stack with the top element of the stack.
 * @head: head of the linked list
 * @count_line: line number;
 * Return: void
 */
void mul_element(stack_t **head, unsigned int count_line)
{
	int j = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, j++)
		;

	if (j < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", count_line);
		_free_vg();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n *= (*head)->n;
	pop_element(head, count_line);
}
