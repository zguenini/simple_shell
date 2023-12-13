#include "shell.h"
/**
 * Function to print a custom error and run.
 *
 * @param argv Program Name
 * @param c Error Count
 * @param cmd Command
 * @return Void
 */
void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}
