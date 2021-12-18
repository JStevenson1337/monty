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
	stack_t *tmp;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
