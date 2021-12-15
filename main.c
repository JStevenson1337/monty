#include "monty.h"
/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	int *file;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: push integer\n");
		exit(EXIT_FAILURE);
	}
	if (*argv[1] == -1)
		exit(EXIT_FAILURE);
	return (1);
}

