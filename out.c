#include "monty.h"

/**
 * pall - prints the stack
 * @stack: stack given by main
 * @line_cnt: ammount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}
/**
 * pchar - prints the int at the top of the stack as char
 * @stack: stack given by main
 * @line_cnt: ammount of lines
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	printf("%c\n", (*stack)->n);
}
/**
* pop - pops the very top
* @stack: stack given by main
* @line_cnt: line number for error messages
*
* Return: void
*/
void pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}
/**
 * pstr - prints the contents of a stack_t stack as a string
 * @stack: stack given by main
 * @line_cnt: line counter for error messages
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
void push(stack_t **stack, unsigned int line_cnt)
{
	stack_t *new = NULL;

	if (!stack)
	{
		fprintf(stderr, "L%d: can't push an empty stack\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "L%d: can't malloc\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	new->n = atoi(strtok(NULL, " \n\t"));
	new->prev = NULL;
	if (!*stack)
	{
		new->next = NULL;
		*stack = new;
		return;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
