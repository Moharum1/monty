#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *head;

	if (global_int < 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = global_int;
	new->prev = head;
	new->next = NULL;

	if (head != NULL)
    {
        head->next = new;
    }

    *stack = new;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    stack_t *head;

	if (line_number == 0)
		return;

    if (*stack == NULL)
    {
        fprintf(stderr, "Stack is empty.\n");
        return;
    }

    head = *stack;
    current = head;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->prev;
    }
}


void free_stack(stack_t **head)
{
	stack_t *current;
	stack_t *old;

	current = *head;

	while(current != NULL)
	{
		old = current;
		current = current->prev;
		free(old);
	}
}