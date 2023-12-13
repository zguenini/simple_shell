#include "shell.h"

/**
 * Function to handle a built-in command.
 *
 * @param cmd Parsed Command
 * @param er Status of the last executed command
 * @return -1 for failure, 0 for success (Return: Execute Builtin)
 */

int handle_builtin(char **cmd, int er)
{
	 bul_t bil[] = {
		{"cd", change_directory},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * Function to execute a simple shell command.
 *
 * @param cmd Parsed Command
 * @param input User Input
 * @c Shell Execution Time Case of Command Not Found
 * @param argv Program Name
 * @return 1 for Command Null, -1 for Wrong Command, 0 for Command Executed
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * Function to handle a captured signal.
 *
 * @param sig Captured Signal
 * @return Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
