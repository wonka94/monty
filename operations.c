#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (!((*stack) && (*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	sum += ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * divide - divides the second top element of the stack by the top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int quotient = 0;

	if (!((*stack) && (*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n == 0))
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	quotient = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = quotient;
}

/**
 * mod - computes the rest of the division of the second top element of
 * the stack by the top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int remainder = 0;

	if (!((*stack) && (*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	remainder = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = remainder;
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int product = 0;

	if (!((*stack) && (*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	product = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = product;
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int diff = 0;

	if (!((*stack) && (*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	diff = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = diff;
}
