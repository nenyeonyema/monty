#include "monty.h"

/**
 * pstr_ - a function that prints the string of the stack.
 * @head: head of the linked list
 * @count_line: the number of lines
 * Return: void
 */
void pstr_(stack_t **head, unsigned int count_line)
{
	stack_t *ptr;
	(void)count_line;

	ptr = *head;

	while (ptr && ptr->n > 0 && ptr->n < 128)
	{
		printf("%c", ptr->n);
		ptr = ptr->next;
	}

	printf("\n");
}
