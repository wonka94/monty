#include "monty.h"

/**
 * execute_instruction - executes a Monty instruction
 * @s: pointer to the instruction string
 * @str: double pointer to the top of the stack
 * @j: line number
 *
 * Description: Extracts the opcode and its argument from the instruction
 * string and executes the corresponding function.
 */
void execute_instruction(char *s, stack_t **str, int j)
{
	char *c = NULL;
	int n = 0, i = 0;
	instruction_t st_fn[] = {{"push", push}, {"pall", pall},
				{"pint", pint}, {"pop", pop},
				{"swap", swap}, {"add", add},
				{"nop", nop}, {"sub", sub},
				{"div", divide}, {"mul", mul},
				{"mod", mod}, {"#", nop},
				{"rotl", rotl}, {"rotr", rotr},
				{"pchar", pchar}, {"pstr", pstr},
				{NULL, NULL}};

	n = get_value(s);
	c = get_command(s);
	if (c)
	if ((n == 6666 && strcmp(c, st_fn[0].opcode) == 0))
	{
		fprintf(stderr, "L%i: usage: push integer\n", j);
		free_stack(*str);
		free(s);
		exit(EXIT_FAILURE);
	}
	while ((st_fn[i].opcode != NULL) && (strcmp(st_fn[i].opcode, c) != 0))
	{
		i++;
	}
	if (!(st_fn[i].opcode))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", j, c);
		free_stack(*str);
		free(s);
		exit(EXIT_FAILURE);
	}
	if (i > 0)
		n = j;
	st_fn[i].f(str, n);
}

/**
 * process_file - processes a Monty bytecode file
 * @fi: pointer to the file
 *
 * Description: Reads and executes the instructions in the file.
 */
void process_file(FILE *fi)
{
	char *s = NULL;
	size_t line_buffer_size = 0;
	int j = 0, x = 1;
	stack_t *str = NULL;

	while (!feof(fi))
	{
		x = 1;
		while (x == 1)
		{
			x = getline(&s, &line_buffer_size, fi);
			j++;
		}
		if (x < 0)
			break;
		execute_instruction(s, &str, j);
	}
	free_stack(str);
	free(s);
}
