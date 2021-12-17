#ifndef MONTY_H
#define MONTY_H

/*
 *Built-in Libraries
 */
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

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

typedef struct BUFFER_S
{
	unsigned char buff[BUFSIZ];
	int i;
} BUFF_T;


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

/*
 * Custom Functions
 */
char (*get_op_func(char *s))(stack_t **stack, unsigned int line_number);



extern int status;

char *opcode(stack_t *stack, char *str, unsigned int line_cnt);

// void push(stack_t **stack, unsigned int line_cnt);
// void pall(stack_t **stack, unsigned int line_cnt);
// void pint(stack_t **stack, unsigned int line_cnt);
// void swap(stack_t **stack, unsigned int line_cnt);
// void pop(stack_t **stack, unsigned int line_cnt);
// void nop(stack_t **stack, unsigned int line_cnt);
// 

// int is_digit(char *string);
// int isnumber(char *str);

// stack_t *add_node(stack_t **stack, const int n);
// stack_t *queue_node(stack_t **stack, const int n);
// void free_stack(stack_t *stack);
// size_t print_stack(const stack_t *stack);
// stack_t *add_node_start(stack_t **head, int n);
// stack_t *add_node_end(stack_t **head, int n);
// stack_t *add_node_at(stack_t **head, unsigned int n, int value);
// stack_t *add_node_at_end(stack_t **head, unsigned int n, int value);




// void file_error(char *argv);
// void error_usage(void);



buff_t *read_line(FILE *file);
buff_t *line_cnt(FILE *file);
#endif
