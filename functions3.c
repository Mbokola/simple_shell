#include "simple_hd.h"

/**
 * path_break - splits the get path in to two
 * @string: to be received
 * @com: command to be executed
 *
 * Return: string to be executed
 */
char *path_break(char *string, char *com)
{
	size_t len, length;
	char *ptr;
	int i = 0, j = 0;
	struct stat st;

	length = _strlen(com);
	while (string)
	{
		len = _strlen(string);
		ptr = malloc(sizeof(char) * (len + length + 2));
		if (!ptr)
			return (NULL);
		while (string[i])
		{
			ptr[i] = string[i];
			i++;
		}
		ptr[i] = '/';
		i += 1;
		while (com[j])
		{
			ptr[i] = com[j];
			i++;
			j++;
		}
		ptr[i] = '\0';
		if (stat(ptr, &st) == 0)
			break;
		i = 0;
		j = 0;
		free(ptr);
		string = strtok(NULL, ":");
	}
	if (!string)
	{
		return (NULL);
	}
	return (ptr);
}
/**
 * _strcmp - used to compare strings with users input
 * @string: string to compare
 * @compare: string to compare with
 * @code: used to determine the return value on success
 *
 * Return: 0 if successful else -1
 */
int _strcmp(char *string, char *compare, int code)
{
	unsigned int len, count = 0;

	len = _strlen(string);
	while (*string && (*string == *compare))
	{
		string++;
		compare++;
		count++;
	}
	if (len == count && code == 2)
		return (2);

	if (*string && (*string != *compare))
	{
		return (-1);
	}
	return (0);
}
/**
 * arguments - checks for the arguments present in the users input
 * @buffer: users input
 *
 * Return: no of arguments present
 */
int arguments(char *buffer)
{
	int count = 0, i = 1;

	while (buffer[count])
	{
		if (buffer[count] == ' ' && buffer[count + 1] != ' ')
			i++;
		count++;
	}
	return (i);
}
/**
 * tokens - used to tokenize the users input
 * @buffer: to be tokenized
 * @tmp: stores the tokenized words
 * @d: delimeter
 *
 * Return: tokenized string
 */
char **tokens(char ***buffer, char ***tmp, char *d)
{
	char *str;
	int count = 0;

	str = strtok(**buffer, d);
	while (str)
	{
		(*tmp)[count] = _strdup(str);
		str = strtok(NULL, d);
		count++;
	}
	return (*tmp);
}
/**
 * execute - used to execute the commands
 * @tmp: tokenized command to be executed
 * @env: environment
 *
 * Return: void
 */
void execute(char **tmp, char **env)
{
	if (execve(tmp[0], tmp, env) == -1)
	{
		perror("Failed to execute\n");
		exit(98);
	}
}
