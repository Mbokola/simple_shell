#ifndef shell
#define shell
extern char **environ;
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

size_t _strlen(const char *s);
char *_strdup(const char *str);
#endif
