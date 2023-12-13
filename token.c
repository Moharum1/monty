#include "monty.h"
/**
* CreateCommandArray - convert string to an array of string according to delim
* @command: the string you want to convert into array
* @delim: the char/String you want to separte your string according to
* @return : an array of string
*/
char **CreateCommandArray(char *command, char *delim)
{
	int tokenCount;
	int i;
	char **tokens;
	char *token;

	tokenCount = 1;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == *delim)
		{
			tokenCount++;
		}
	}

	tokens = (char **)malloc((tokenCount + 1) * sizeof(char *));

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, delim);
	i = 0;

	while (token != NULL)
	{
		tokens[i] = _strdup(token);

		if (tokens[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
* freeTokens - free the memory allocated by a string array
* @tokens: the string array
* @tokencount: the number of Strings in the array
* @return : none
*/
void freeTokens(char **tokens, int tokenCount)
{
	int i;

	for (i = 0; i < tokenCount; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

/**
* getStringArraySize - get the number of elements in an array
* @array: the array you have
* @return : the number of argument in the array
*/
int getStringArraySize(char **array)
{
	int i;
	int counter = 0;

	for (i = 0; array[i] != NULL; i++)
	{
		counter++;
	}
	return (counter);
}

char* readLine(FILE* file) {
    char buffer[100];
    char* line = NULL;
    size_t length = 0;

    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        length = strlen(buffer);

        /*Check if the line ends with a newline character*/
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';  /*Remove the newline*/
            length--;  /*Update the length*/
        }

        line = (char*)malloc((length + 1) * sizeof(char));

        if (line != NULL) {
            strcpy(line, buffer);
        } else {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
    }

    return line;
}

char* _strdup(const char* source){
    size_t length;
	char *destination;
	
	if (source == NULL) {
        return NULL;
    }

	length = strlen(source) + 1;
    destination = (char*)malloc(length);

    if (destination != NULL) {
        strcpy(destination, source);
    } else {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    return destination;
}
