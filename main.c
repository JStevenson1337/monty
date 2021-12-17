#include "monty.h"

int status = 0;



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
	BUFF_T *buff;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;



	if(argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}



	file = fopen(argv[1], "r");

	while ((read = getline(&line, &len, file)) != -1)	// read line by line
	{
		line_number++;
		buff = read_line(file);
		if(buff->opcode != NULL)
		{
			printf("%s\n", buff->opcode);
			opcode(&stack, buff->opcode, line_number);
		}
		else
		{
			printf("L%d: unknown instruction %s\n", line_number, buff->opcode);
			status = 1;
		}
		opcode(&stack, buff->buff, line_number);
		free(buff->buff);
		free(buff);


	
	}

	free(line);
	fclose(file);
	free_stack(stack);
	return (status);

}

