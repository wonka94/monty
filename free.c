#include "monty.h"

/**
 * free_z - frees a stack_t stack
 * @st: pointer to the top of the stack
 *
 * Description: Frees a stack_t stack.
 */
void free_stack(stack_t *s)
{
	stack_t *temp = NULL;

	while (s)
	{
		temp = s->next;
		free(s);
		s = temp;
	}
}
