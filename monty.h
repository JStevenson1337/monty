#ifndef MONTY_H
#define MONTY_H

/*
 *Built-in Libraries
 */
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

/*
 * Custom Functions
 */
		/*
		 * pall.c
		 */

int *open_file(char *file);



/**
 * struct BUFFER_S
 * @i: counter
 * @buff: stores the sizeof buff
 */
typedef struct BUFFER_S
{
	unsigned char buff[BUFSIZ];
	int i;
} BUFF_T;

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


#endif
