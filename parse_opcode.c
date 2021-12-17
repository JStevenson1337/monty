#include "monty.h"
/**
 * opcode_lookup - function that looks up opcode
 * @line: line of code
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: 0
 */
void opcode_lookup(char *line, int **stack, unsigned int line_number)
{
	int i = 0;
	char *opcode[] = {"push", "pall", "pint", "pop", "swap", "add", "nop", "sub", "div", "mul", "mod", "pchar", "pstr"};
	void (*f[11])(int **stack, unsigned int line_number) = {
		push,
		pall,
		//sub,
		// div,
		// mul,
		// mod,
		// pchar
	};
	for (i = 0; i < '\0'; i++)
	{
		if (strncmp(line, opcode[i], strlen(opcode[i])) == 0)
		{
			f[i](stack, line_number);
			break;
		}
	}
	if (i == 11)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
		exit(EXIT_FAILURE);
	}
}

