#include "shell.h"

/**
 * Function to terminate the Shell with a specified status.
 *
 * @param cmd Parsed Command
 * @param input User Input
 * @param argv Program Name
 * @param c Execute Count
 * @return Void (Exit Status)
 */
void exit_bul(char **cmd, char *input, char **argv, int c)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}

	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_prerror(argv, c, cmd);
			break;
		}
		else
		{
			status = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(status);
		}
	}
}

/**
 * Function to change the current working directory.
 *
 * @param cmd Parsed Command
 * @param er Status of Last Executed Command
 * @return 0 for success, 1 for failure
 */
int change_directory(char **cmd, __attribute__((unused)) int er)
{
	int result = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		result = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		result = chdir(getenv("OLDPWD"));
	}
	else
		result = chdir(cmd[1]);

	if (result == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (result != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * Function to display environment variables.
 *
 * @param cmd Parsed Command
 * @param er Status of Last Executed Command
 * @return Always 0
 */
int dis_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * Function to display help for built-in commands.
 *
 * @param cmd Parsed Command
 * @param er Status of Last Executed Command
 * @return 0 for success, -1 for failure
 */
int display_help(char **cmd, __attribute__((unused)) int er)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}

	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}

	_putchar('\n');
	return (0);
}

/**
 * Function to execute the echo command.
 *
 * @param cmd Parsed Command
 * @param st Status of Last Executed Command
 * @return 0 for success or execute normal echo
 */
int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_in(st);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);
	}
	else
		return (print_echo(cmd));

	return (1);
}
