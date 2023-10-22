#include "monty.h"

/**
 * push_element - a function that pushes an element into the stack
 * @head: double pointer to head of the list
 * @count: line number
 * Return: void
 */
void push_element(stack_t **head, unsigned int count)
{
	int m, n;

	if (!vg.arg)
	{
		dprintf(2, "L%u: usage: push integer\n ", count);
		_free_vg();
		exit(EXIT_FAILURE);
	}

	for (n = 0; vg.arg[n] != '\0'; n++)
	{
		if (!isdigit(vg.arg[n]) && vg.arg[n] != '-')
		{
			dprintf(2, "L%u: usage: push integer\n", count);
			_free_vg();
			exit(EXIT_FAILURE);
		}
	}

	m = atoi(vg.arg);

	if (vg.lifo == 1)
		add_new_beg_node(head, m);
	else
		add_new_end_node(head, m);
}

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
