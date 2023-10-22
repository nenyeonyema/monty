#include "monty.h"

/**
 * rotl_ - a function that rotates the first element
 * to the bottom and the second to the top
 * @head: head of the linked list
 * @count_line: yhe number of lines
 * Return: void
 */
void rotl_(stack_t **head, unsigned int count_line)
{
	stack_t *ptr = NULL;
	stack_t *temp = NULL;
	(void)count_line;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	ptr = (*head)->next;
	temp = *head;

	for (; temp->next != NULL; temp = temp->next)
		;

	ptr->prev = NULL;
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	*head = ptr;
}

