#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#define NUMBUILTIN_CMD 2
#define SIZEOFPARSE_STR 32
extern char **environ;

void sig_handler(int signum);
int _strcmp(char *dest, char *src);
char **parse_str(char *str);
void _execute(char **arg, char **argv);
int _bexit(void);
int _benv(void);
int check_builtin(char **arr);

#endif
