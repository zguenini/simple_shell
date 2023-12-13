#include "shell.h"

/**
 * Function to display the shell prompt and run.
 */
void prompt(void)
{
	PRINTER("$ ");
}
/**
 * Function to display error based on user input, counter, and program name.
 *
 * @param input User Input
 * @param counter Simple Shell Count Loop
 * @param argv Program Name
 * @return Void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
