#include "monty.h"
/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	int i = 0;

	char self = *argv[0];
	const char *file = *argv[1];
	char line_number = *argv[2];

	FILE *reader = fopen(file, "r");
	while (reader != NULL)
	{
		char *line = NULL;
		size_t len = 0;
		ssize_t read;
		read = getline(&line, &len, reader);
		if (line[0] == '#')
		{
			free(line);
			line = NULL;
			continue;
		}
		if (line[0] == '\n')
		{
			free(line);
			line = NULL;
			continue;
		}
		if (line[0] == '\0')
		{
			free(line);
			line = NULL;
			continue;
		}
		printf("%s", line);
		for (i = 0; line[i] != '\0'; i++)
		{
			if (line[i] == ' ')
			{
				line[i] = '\0';
				break;
			}
		}
		free(line);
		line = NULL;
	}
	fclose(reader);
	return (0);

}



/*
*	EXAMPLE: 
*	>>>$ ./a.out hello there
*	argv[0]: ./a.out
*	argv[1]: hello
*	argv[2]: there
*/
