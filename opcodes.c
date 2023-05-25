#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @s: double pointer to the top of the stack
 * @ln: line number
 *
 * Description: If the stack is empty, prints an error message
 * and exits with EXIT_FAILURE.
 */
void pop(stack_t **s, unsigned int ln)
{
	stack_t *temp;

	if (*s == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = *s;
	*s = (*s)->next;
	free(temp);
}

/**
 * push - adds a new element to the top of the stack
 * @top: double pointer to the top of the stack
 * @line_num: line number
 *
 * Description: If malloc fails, prints an error message and exits
 * with EXIT_FAILURE.
 */
void push(stack_t **top, unsigned int line_num)
{
	stack_t *new_stack = malloc(sizeof(stack_t));

	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	new_stack->n = line_num;
	new_stack->prev = NULL;
	new_stack->next = *top;

	if (*top != NULL)
		(*top)->prev = new_stack;

	*top = new_stack;
}

/**
 * swap - swaps the top two elements of the stack
 * @s: double pointer to the top of the stack
 * @ln: line number
 *
 * Description: If the stack contains less than two elements,
 * prints an error message and exits with EXIT_FAILURE.
 */
void swap(stack_t **s, unsigned int ln)
{
	stack_t *temp;
	int t;

	if (*s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = *s;
	t = temp->n;
	temp->n = temp->next->n;
	temp->next->n = t;
}

/**
 * nop - doesn't do anything
 * @s: double pointer to the top of the stack
 * @ln: line number
 *
 * Description: This function doesn't do anything.
 */
void nop(stack_t **s, unsigned int ln)
{
	(void) ln;
	(void) s;
}
