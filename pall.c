#include "monty.h"

/**
 * pall - prints the stack
 * @stack: stack pointer
 * @line_cnt: # of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}
