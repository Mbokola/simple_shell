#ifndef simple_shell
#define simple_shell

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

int _strcmp(char *string, char *compare, int code);
int arguments(char *buffer);
char **tokens(char ***buffer, char ***tmp, char *d);
void execute(char **tmp, char **env);
size_t _strlen(const char *s);
char *command(char *str);
char *get_env(char **env, char *str);
char *get_path(char *path, char *cmd);
char *_strcpy(char *dest, char *origin);
int main_break(char **buffer, char **env);
char *append(char **ptr, const char *rec);
void print_env(char **env);
char *path_break(char *string, char *com);
char *_strdup(const char *str);
void set_free(char ***str);

#endif
