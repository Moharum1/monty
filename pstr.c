#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *head;
    char *string;
    char buffer[1024]; 

    head = *stack;
    string = buffer;

    if (head == NULL || line_number == 0)
    {
        printf("\n");
        return;
    }

    while (head != NULL)
    {
        if (head->n == 0 || head->n > 127)
            break;

        *string = (char)head->n;
        string++;
        head = head->prev;
    }

    *string = '\0';
    printf("%s\n", buffer);
}
