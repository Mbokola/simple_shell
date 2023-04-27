#include "simple_hd.h"

/**
 * set_free - free allocated memory
 * @str: array of strings to be freed
 *
 * Return: void
 */
void set_free(char ***str)
{
	int i;

	for (i = 0; (*str)[i]; i++)
	{
		free((*str)[i]);
		(*str)[i] = NULL;
	}
}
/**
 * _strdup - creates a duplicate
 * @str: string to duplicated
 *
 * Return: duplicated string
 */
char *_strdup(const char *str)
{
	size_t len = _strlen(str) + 1;
	char *duplicate = malloc(len);
	int i = 0;

	if (duplicate != NULL)
	{
		for (i = 0; str[i]; i++)
			duplicate[i] = str[i];
		duplicate[i] = '\0';

	}
	return (duplicate);
}
/**
 * print_env - prints the evironment
 * @env: environment string
 *
 * Return: void
 */
void print_env(char **env)
{
	int n = 0;
	size_t size;

	while (env[n] != NULL)
	{
		size = _strlen(env[n]);
		write(STDOUT_FILENO, env[n], size);
		write(STDOUT_FILENO, "\n", 2);
		n++;
	}
}
/**
 * main_break - tackles some of main tasks
 * @buffer: users input
 * @env: environment
 * @argv: Arguments received
 * Return: 0 if successful else -1
 */
int main_break(char **buffer, char **env, char **argv)
{
	int i, status;
	char **tmp, *test, *ptr, *get_command;
	pid_t child;

	i = arguments(*buffer) + 1;
	tmp = malloc(sizeof(char *) * i);
	if (!tmp)
		return (-1);
	tmp[i - 1] = NULL;
	tmp = tokens(&buffer, &tmp, " ");
	get_command = command(tmp[0]);
	ptr = get_env(env, "PATH");
	test = get_path(ptr, get_command);
	if (test)
	{
		tmp[0] = _strdup(test);
		free(test);
		child = fork();
		if (child == 0)
		{
			execute(tmp, env);
			exit(EXIT_SUCCESS);
		}
		else
			wait(&status);
		set_free(&tmp);

	}
	else
	{
		write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
		perror(" ");
	}
	free(tmp);
	return (0);
}
/**
 * str_cat - concatenates two strings
 * @dest: string to be ammended
 * @buffer: string to be attached to dest
 *
 * Return: concatenated string
 */
char *str_cat(char *dest, const char *buffer)
{
	size_t n;

	n = _strlen(dest);
	while (*buffer != '\0')
	{
		dest[n++] = *buffer++;
	}
	dest[n] = '\0';
	return (dest);
}
