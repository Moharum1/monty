#include "monty.h"

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
    stack_t *old;

	head = *stack;

    if (head == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

    old = head->prev;

    if(old == NULL)
    {
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
    }

    old->n = old->n - head->n;
    pop(stack, line_number);
}
