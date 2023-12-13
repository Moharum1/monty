#include "monty.h"


instruction_t instructions[] = {
	{"pall", pall},
	{"push", push},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", divide},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{NULL, NULL}
};

int global_int;

int main(int argc, char **argv)
{
	char *line;
	FILE *file;
	char *delim;
	char **tokens;
	instruction_t *inst;
	stack_t *stack = NULL;
	int counter;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	delim = " ";
	counter = 1;

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line = readLine(file)) != NULL)
	{
		if (strcmp(line," ") != 0)
		{
			tokens = CreateCommandArray(line, delim);	
			for (inst = instructions; inst->opcode != NULL; inst++)
			{
				if (strcmp(inst->opcode, tokens[0]) == 0)
				{
					if (tokens[1] != NULL)
						global_int = atoi(tokens[1]);

					inst->f(&stack, counter);
					break;
				}
			}

			if (!checkForOp(tokens[0]))
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", counter, line);
				exit(EXIT_FAILURE);
			}

		counter++;
		}
		freeTokens(tokens, getStringArraySize(tokens));
		free(line);
	}
	fclose(file);
	free_stack(&stack);
	return (0);
}

bool checkForOp(char *op)
{
	instruction_t *inst;
	for (inst = instructions; inst->opcode != NULL; inst++)
	{
		if (strcmp(inst->opcode, op) == 0)
		{
			return true;
		}
	}

	return false;
}