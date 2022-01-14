#include "monty.h"
/***
 * Pushes an element to the stack.
*/void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *value;
	int i = 0, j = 0;

	value = malloc(sizeof(char));
	if (value == NULL)
		return;

	while (line[i] < '0' || line[i] > '9')
	{
		if (line[i] == '\0')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		if (line[i] == '-')
		{
			value[j] = line[i];
			j++;
		}
		i++;
	}
	while (line[i] != ' ' && line[i] != '\0'
		   && line[i] >= '0' && line[i] <= '9')
	{
		value[j] = line[i];
		i++;
		j++;
	}
	value[j] = '\0';
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = atoi(value);
	node->prev = NULL;
	if (*stack == NULL)
		node->next = NULL;
	else
	{
		node->next = *stack;
		(*stack)->prev = node;
	}
	*stack = node;
	free(value);
}

/***
 * Prints all the values on the stack, starting from the top of the stack
 */void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	temp = *stack;
	if (temp ==NULL)
	  (void) temp;;
	
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
				temp = temp->next;
	}
}

/***
 * Prints the value at the top of the stack, followed by a new line.
 */void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/***
 * Removes the top element of the stack.
 */void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;
	free(temp);
}


/***
 * Swaps the top two elements of the stack.
 */void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	int count = 0;
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
