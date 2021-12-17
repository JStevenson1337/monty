#include "monty.h"
/**
 * open_file - opens file
 * @file: pointer to file to open
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
		BUFF_T *buff = malloc(sizeof(BUFF_T));
		buff->i = 0;
		int j = 0;
		while (line[j] != '\0')
		{
			buff->buff[j] = line[j];
			j++;
		}
		buff->buff[j] = '\0';
		free(line);
		line = NULL;
		len = 0;
		read = getline(&line, &len, fp);
		if (buff->buff[0] == '#')
		{
			free(buff);
			buff = NULL;
			continue;
		}
		if (buff->buff[0] == '\n')
		{
			free(buff);
			buff = NULL;
			continue;
		}
		if (buff->buff[0] == '\0')
		{
			free(buff);
			buff = NULL;
			continue;
		}

		*i = *i + 1;
	}
	fclose(fp);
	if (line)
		free(line);
	return (i);
}
