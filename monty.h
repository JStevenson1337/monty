#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <stdarg.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define op_check { \
		{"push", push},\
		{"pall", pall},\
		{"pint", pint},\
		{"pop", pop},\
		{"swap", swap},\
		{"add", add},\
		{"nop", nop},\
		};

		/*
		* TODO: Add more opcodes here
		*/
	
/**
* struct help - args for the current opcode
* @blob: stack mode, stack (default) and queue
* @args: the args of the string
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct help
{
	int blob;
	char *args;
} help;
help global;

extern int status;

void opcode(stack_t **stack, char *str, unsigned int line_cnt);

void push(stack_t **stack, unsigned int line_cnt);
void pall(stack_t **stack, unsigned int line_cnt);
void pint(stack_t **stack, unsigned int line_cnt);
void swap(stack_t **stack, unsigned int line_cnt);
void pop(stack_t **stack, unsigned int line_cnt);
void nop(stack_t **stack, unsigned int line_cnt);
void add(stack_t **stack, unsigned int line_cnt);
/*
 *TODO: Add more opcodes here
 */

int is_digit(char *string);
int isnumber(char *str);

stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);




#endif /* MONTY_H */
