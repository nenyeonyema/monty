#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glo - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct glo
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} glo_t;

extern glo_t vg;

void push_element(stack_t **head, unsigned int count);
void pall_element(stack_t **head, unsigned int count);
void pint_element(stack_t **head, unsigned int count_line);
void pop_element(stack_t **head, unsigned int count_line);
void swap_element(stack_t **head, unsigned int count_line);
void add_element(stack_t **head, unsigned int count_line);
void nop_(stack_t **head, unsigned int count_line);
void sub_element(stack_t **head, unsigned int count_line);
void div_element(stack_t **head, unsigned int count_line);
void mul_element(stack_t **head, unsigned int count_line);
void mod_element(stack_t **head, unsigned int count_line);
void pchar_(stack_t **head, unsigned int count_line);
void pstr_(stack_t **head, unsigned int count_line);
void rotl_(stack_t **head, unsigned int count_line);
void rotr_(stack_t **head, unsigned int count_line);
void stack_(stack_t **head, unsigned int count_line);
void queue_(stack_t **head, unsigned int count_line);


stack_t *add_new_end_node(stack_t **head, const int num);
stack_t *add_new_beg_node(stack_t **head, const int num);
void _freedlist(stack_t *head);


void _free_vg(void);
void _start_vg(FILE *sfd);
FILE *check_file(int argc, char *argv[]);


void (*implement(char *opc))(stack_t **stack, unsigned int line_number);
int _strcmp(char *str1, char *str2);
int _sch(char *str, char ch);
char *_strtoky(char *str, char *delim);

#endif
