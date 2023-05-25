#include "monty.h"

/**
 * get_command - gets the command from a string
 * @c: pointer to the string
 *
 * Return: pointer to the command
 */
char *get_command(char *c)
{
	int i = 0;
	int search = 0;

	while (c[i] != '\0')
	{
		if (c[i] == '#')
			return ("#");

		if (!islower(c[i]))
		{
			if (search == 1)
			{
				c[i] = '\0';
				return (c);
			}
			else
				c++;
		}
		else
		{
			i++;
			search = 1;
		}
	}
	return (c);
}

/**
 * get_value - gets the value from a string
 * @c: pointer to the string
 *
 * Return: the value as an integer
 */
int get_value(char *c)
{
	size_t i = 0;
	size_t j = 0;
	int search = 0;
	char ch[48];

	while (c[i] != '\0')
	{
		if (isdigit(c[i]))
		{
			search = 1;
			ch[j] = c[i];
			j++;
		}
		i++;
	}
	ch[j] = '\0';

	if (search == 1)
		return (atoi(ch));
	else
		return (6666);
}
