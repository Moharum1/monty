#include "monty.h"

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;

    if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

    if (head->n < 41 || head->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
    }

    printf("%c\n", head->n);
}
