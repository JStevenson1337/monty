#include "monty.h"


int status = 0;
/**
 * main - entry point
 * @argv: list of args
 * @argc: num of args
 *
 * Return: exit status
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	FILE *file;
	char *buffer = NULL;
	size_t buf_len = 0;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_cnt = 1;


	global.blob = 1;
	
	
if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while (getline(&buffer, &buf_len, file) != -1)
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_cnt++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_cnt++;
			continue;
		}
		global.args = strtok(NULL, " \t\n");
		opcode(&stack, str, line_cnt);
		line_cnt++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(status);
}
