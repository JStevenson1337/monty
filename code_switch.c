#include "monty.h"


/**
 * @brief 
 * 
 */
int find_command(char *command)
{
	int i = 0;

	while (i < NUM_COMMANDS)
	{
		if (strcmp(command, commands[i].name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

	
	switch (opcode)
	{
	case 'push':
		instruction_t->opcode = "push";
		instruction_t->f = push;
		break;
	case 'opcode':
		instruction_t->opcode = "opcode";
		instruction_t->f = opcode;
		break;
	case 'pint'
		instruction_t->opcode = "pint";
		instruction_t->f = pint;
		break;
	case 'pop':
		instruction_t->opcode = "pop";
		instruction_t->f = pop;
		break;
	case 'swap':
		instruction_t->opcode = "swap";
		instruction_t->f = swap;
		break;
	case 'add':
		instruction_t->opcode = "add";
		instruction_t->f = add;
		break;
	case 'nop':
		instruction_t->opcode = "nop";
		instruction_t->f = nop;
		break;
	case 'sub':
		instruction_t->opcode = "sub";
		instruction_t->f = sub;
		break;
	case 'div':
		instruction_t->opcode = "div";
		instruction_t->f = div;
		break;
	case 'mul':	
		instruction_t->opcode = "mul";
		instruction_t->f = mul;
		break;
	case 'mod':
		instruction_t->opcode = "mod";
		instruction_t->f = mod;
		break;
	case 'pchar':
		instruction_t->opcode = "pchar";
		instruction_t->f = pchar;
		break;
	case 'pstr':
		instruction_t->opcode = "pstr";
		instruction_t->f = pstr;
		break;
	case 'rotl':
		instruction_t->opcode = "rotl";
		instruction_t->f = rotl;
		break;
	case 'rotr':
		instruction_t->opcode = "rotr";
		instruction_t->f = rotr;
		break;
	case 'stack':
		instruction_t->opcode = "stack";
		instruction_t->f = stack;
		break;
	case 'queue':
		instruction_t->opcode = "queue";
		instruction_t->f = queue;
		break;
	default:
		printf("Error: unknown instruction %s\n", opcode);
		exit(EXIT_FAILURE);
	}
	return (instruction_t);
