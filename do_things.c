#include "monty.h"

char push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return (0);
	}
	temp = *head;
	temp->prev = new_node;

	new_node->next = temp;

	return (0);
}

int pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return (0);
}
