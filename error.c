#include "monty.h"
/**
 * error_usage - prints usage message and exits
 *
 * Return: nothing
 */
void error_usage(void)
{
	
}

/**
 * file_error - prints file error message and exits
 * @argv: argv given by manin
 *
 * Return: nothing
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
