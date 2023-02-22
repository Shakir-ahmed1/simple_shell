#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#define DELIM " \n"
#define NUMBUILTIN_CMD 2
#define SIZEOFPARSE_STR 1024
extern char **environ;

void sig_handler(int signum);
char **parse_str(char *str);
void _execute(char **arg, char **argv);

#endif
