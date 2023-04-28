#include "simple_hd.h"

/**
 * _strcpy - copies data to another string
 * @dest: copied to
 * @origin: to be copied
 *
 * Return: copied string
 */
char *_strcpy(char *dest, char *origin)
{
	int n;

	n = 0;
	while (origin[n] != '\0')
	{
		dest[n] = origin[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}
/**
 * _strlen - determines the length of a string
 * @s: string to be measured
 *
 * Return: length of string
 */
size_t _strlen(const char *s)
{
	size_t i = 0;

	while (s[i])
		i++;
	return (i);
}
/**
 * get_env - used to get path in the environment
 * @env: environment
 * @str: string to be searched for
 *
 * Return: path where string is found
 */
char *get_env(char **env, char *str)
{
	char *str2;
	int j, i = 0;

	str2 = env[i];
	while (env[i])
	{
		j = _strcmp(str, str2, 2);
		if (j == 2)
		{
			break;
		}
		else
		{
			i++;
			str2 = env[i];
		}
	}
	return (env[i]);
}
/**
 * get_path - zeros down the path to used to excute
 * @path: path to utilized
 * @cmd: command to be executed
 *
 * Return: string to used in the execution of command
 */
char *get_path(char *path, char *cmd)
{
	char *store, *save_link;
	struct stat st;

	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
		{
			return (cmd);
		}
		else
		{
			free(cmd);
			return (NULL);
		}
	}
	store = _strdup(path);
	save_link = store;
	store = strtok(store, "=");
	store = strtok(NULL, ":");
	store = path_break(store, cmd);
	if (!store)
	{

		free(save_link);
		free(cmd);
		return (NULL);
	}
	free(save_link);
	free(cmd);
	return (store);
}
