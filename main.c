#include "monty.h"
/**
* main - main function
* @argc: number of arguments
* @argv: arguments
* Return: 0
*/
int main(char argc, char **argv)
{
int i = 0;
int *stack = NULL;
FILE *fp;
char *line = NULL;
size_t len = 0;
ssize_t read;
unsigned int line_number = 0;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
fp = fopen(argv[1], "r");
while ((read = getline(&line, &len, fp)) != -1)
{
line_number++;
if (line[0] == '#')
continue;
if (line[0] == '\n')
continue;
}
printf("%d\t", line_number);
printf("%s\n", line);
while (*line)
{
opcode_lookup(line, &stack, line_number);
line++;
}
free(line);
fclose(fp);
return (0);
}
/*
*	EXAMPLE:
*	>>>$ ./a.out hello there
*	argv[0]: ./a.out
*	argv[1]: hello
*	argv[2]: there
*/
