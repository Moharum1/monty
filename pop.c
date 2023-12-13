#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;

    if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

    *stack = head->prev;

    if(*stack != NULL)
    {
        (*stack)->next = NULL;
    }

    free(head);
}
