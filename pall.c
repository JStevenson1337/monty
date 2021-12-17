#include "monty.h"

void pall(stack_t **stack, unsigned int line_cnt)
{
	stack_t *temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
