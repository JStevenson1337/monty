#include "monty.h"

/**
 * push - push element into the stack
 * @stack:  stack pointer
 * @line_cnt: ammount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	char *n = global.args;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	if (global.blob == 1)
	{
		if (!add_node(stack, atoi(global.args)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.args)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
}
