#include "monty.h"

void opcode(stack_t **stack, char *str, unsigned int line_cnt)
{
	int i = 0;

	instruction_t op[] = op_check;

	if (!strcmp(str, "stack"))
	{
		global.blob = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.blob = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_cnt);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, str);
	status = EXIT_FAILURE;
}
