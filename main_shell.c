#include "simple_hd.h"

/**
 * main - entry point
 * @ac: no of arguments
 * @argv: argument entered
 * @env: environment
 *
 * Return: 0 if successful and -1 otherwise
 */
int main(int ac, char **argv, char **env)
{
	char *buffer = NULL;
	size_t line_len = 0;
	ssize_t length = 0;
	int status, loop = 1;

	if (ac == 1)
	{
		while (loop)
		{
			if (!(isatty(STDIN_FILENO)))
				loop = 0;
			if (loop)
				write(STDOUT_FILENO, "($) ", 4);
			length = getline(&buffer, &line_len, stdin);
			if (length == -1)
			{
				write(STDOUT_FILENO, "\n", 2);
				break;
			}
			if (_strcmp(buffer, "exit\n", 1) == 0)
				break;
			if (_strcmp(buffer, "env\n", 1) == 0)
				print_env(env);
			else
			{
				buffer[length - 1] = '\0';
				if (length != 1)
				{
					status = main_break(&buffer, env, argv);
					if (status == -1)
						break;
				}
				else
					continue;
			}
		}
		free(buffer);
	}
	return (0);
}
