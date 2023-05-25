#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 *
 * Description: Prints all the values on the stack, starting from the top.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 *
 * Description: Prints the char at the top of the stack, followed by a new line
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 *
 * Description: Prints the value at the top of the stack followed by a new line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 *
 * Description: Prints the string starting at the top of the stack,
 * followed by a new line.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
