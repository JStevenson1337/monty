#include "monty.h"

stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (!*head)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	new->prev = *head;
	(*head)->next = new;
	*head = new;
	return (new);
}


stack_t *add_node_start(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	if (!*head)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	return (new);
}

stack_t *add_node_at(stack_t **head, unsigned int n, int value)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *head;

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	if (!*head)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (new);
	}
	if (n == 0)
		return (add_node_start(head, value));
	if (n == 1)
		return (add_node_end(head, value));
	while (current)
	{
		if (n == current->n)
		{
			new->next = current->next;
			new->prev = current;
			current->next->prev = new;
			current->next = new;
			return (new);
		}
		current = current->next;
	}
	return (NULL);
}

stack_t *add_node_at_end(stack_t **head, unsigned int n, int value)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *head;

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	if (!*head)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (new);
	}
	if (n == 0)
		return (add_node_start(head, value));
	if (n == 1)
		return (add_node_end(head, value));
	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			return (new);
		}
		current = current->next;
	}
	return (NULL);
}


