#include "monty.h"

/**
 * is_digit - checks if a string is a digit
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(char *string)
{
	int i = 0;

	if (string[i] == '-')
		i++;
	while (string[i])
	{
		if (string[i] < '0' || string[i] > '9')
			return (0);
		i++;
	}
	return (1);

}

/**
 * isnumber - checks if a string is a number
 * @str: string to check
 *
 * Return: 1 if the string is a number, else, 0.
 */
int isnumber(char *str)
{
	int i;

	if (!str)
	{
		return (0);
	}

	for (i = 0; str[i]; i++)
	{
		if (i < '0' || i > '9')
			return (0);
	}

	return (1);
}
