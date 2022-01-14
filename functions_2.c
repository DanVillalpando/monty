#include "monty.h"

/***
 * Adds the top two elements of the stack.
 */void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum;
	int count = 0;
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/***
 * Doesn’t do anything.
 */void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
