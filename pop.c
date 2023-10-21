#include "monty.h"

/**
 * pop_element - removes the top element of the stack
 * @head: head of the linked list
 * @count_line: the number of lines
 * Return: void
 */
void pop_element(stack_t **head, unsigned int count_line)
{
	stack_t *ptr;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", count_line);
		_free_vg();
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	*head = (*head)->next;
	free(ptr);
}
