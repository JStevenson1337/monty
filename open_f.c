#include "monty.h"
/**
 * open_file - opens file
 * @file: file to open
 * Return: file pointer
 */

int *open_file(char *file)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int *i = malloc(sizeof(int));
	*i = 0;
	fp = fopen(file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("%s", line);
		*i = *i + 1;
	}
	fclose(fp);
	if (line)
		free(line);
	return (i);
}
