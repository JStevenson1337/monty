#include "monty.h"

stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new_node;
	stack_t *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	temp = *head;
	temp->next = new_node;

	new_node->prev = temp;

	return (new_node);
}


stack_t *add_node_start(stack_t **head, int n)
{
	stack_t *new_node;
	stack_t *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}
	temp = *head;
	temp->prev = new_node;

	new_node->next = temp;

	return (new_node);
}

stack_t *add_node_at(stack_t **head, unsigned int n, int value)
{
	stack_t *new_node;
	stack_t *temp;
	stack_t *temp2;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}
	temp = *head;
	temp2 = *head;
	while (temp != NULL && n > 0)
	{
		temp2 = temp;
		temp = temp->next;
		n--;
	}
	if (temp == NULL)
	{
		new_node->next = NULL;
		temp2->next = new_node;
		return (new_node);
	}
	temp2->next = new_node;
	new_node->prev = temp2;
	new_node->next = temp;
	temp->prev = new_node;
	return (new_node);
}

stack_t *add_node_at_end(stack_t **head, unsigned int n, int value)
{
	stack_t *new_node;
	stack_t *temp;
	stack_t *temp2;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}
	temp = *head;
	temp2 = *head;
	while (temp != NULL)
	{
		temp2 = temp;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		new_node->next = NULL;
		temp2->next = new_node;
		return (new_node);
	}
	temp2->next = new_node;
	new_node->prev = temp2;
	new_node->next = temp;
	temp->prev = new_node;
	return (new_node);
}


