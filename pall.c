#include "monty.h"
/**
 * open_file - opens file
 * @file: file to open
 * Return: file pointer
 */

pall_op_t *open_file(char *file)
{
	pall_op_t *head = NULL;
	pall_op_t *new = NULL;
	int fd;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int line_number = 1;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fd)) != -1)
	{
		new = malloc(sizeof(pall_op_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new->opcode = strtok(line, " \n\t");
		new->f = get_op_func(new->opcode);
		new->line_number = line_number;
		if (head == NULL)
			head = new;
		else
			add_node_end(head, new);
		line_number++;
	}
	free(line);
	close(fd);
	return (head);
}
