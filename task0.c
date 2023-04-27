#include "main.h"

/**
 *main - Entry point
 *
 *Return: 0 on success
 */
int main(void)
{
	char **tmp = NULL, *input = NULL;
	size_t n = 0;
	ssize_t length = 0;
	pid_t child;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		length = getline(&input, &n, stdin);
		if (length == -1)
		{
			free(input);
			break;
		}
		input[length - 1] = '\0';
		tmp = malloc(sizeof(char *) * strlen(input) + 1);
		tmp[1] = NULL;
		tmp[0] = strdup(input);
		child = fork();
		if (child == 0)
		{
			if (execve(tmp[0], tmp, environ) == -1)
				perror("File not found");
		}
		else
			wait(&status);
		free(tmp[0]);
		free(tmp);
		free(input);
	}
	free(input);
	return (0);
}
