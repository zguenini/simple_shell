#include "shell.h"

/**
 * Function to parse a line and run.
 *
 * @param input User Input to parse
 * @return Array of char (Parsed): Simple Shell
 */
char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
