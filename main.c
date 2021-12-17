#include "monty.h"




/**
 * main - entry point
 * @argv: list of arguments passed to our program
 * @argc: ammount of args
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{


	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_cnt = 1;

	file = fopen(argv[1], "r");


	while (getline(&buffer, &buf_len, file) != -1)
	{
		str = strtok(buffer, "\n\t\r");
		if (str != NULL)
		{
			execute_opcode(&stack, str, line_cnt);
		}
		line_cnt++;
	}

	{

		execute_opcode(&stack, str, line_cnt);
		opcode(&stack, str, line_cnt);
		line_cnt++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(status);
}
