#include "monty.h"

/**
 * pall_element - a function that prints all values on the stack
 * @head: head of the linked list
 * @count: line numbers
 * Return: no return
 */
void pall_element(stack_t **head, unsigned int count)
{
	stack_t *ptr;
	(void)count;

	ptr = *head;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
