#include "monty.h"

void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
    stack_t *old;

	head = *stack;

    if (head == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

    old = head->prev;

    if (old == NULL)
    {
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
    }

    if (head->n == 0)
    {
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
    }

    old->n = old->n / head->n;
    pop(stack, line_number);
}
