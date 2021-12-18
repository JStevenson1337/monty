#include "monty.h"

/**
 * queue_node - adds a node to a stack_t stack in queue node
 * @stack: stack head
 * @n: number of the node
 *
 * Return: new node
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
	}
	return (new_node);
}

/**
 * add_node - adds nod to stack
 * @stack: stack head
 * @n: number of the node
 * @line_cnt: line number
 * Return: new node
 * 
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
	}
	return (new_node);
}

/**
 * print_stack - prints stack
 * @stack: stack head
 *
 * Return: list length
 */
size_t print_stack(const stack_t *stack)
{
	size_t len = 0;

	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		len++;
	}
	return (len);
}

/**
 * free_stack - frees stack
 * @stack: list head
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
