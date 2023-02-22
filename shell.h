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
int _strcmp(char *dest, char *src);
int _strlen(char *);
char **parse_str(char *str);
void _execute(char **arg, char **argv, char **env);
int _exit_shell(void);
int _print_env(void);
int check_builtin(char **arr);
int char_counter(char *str, char c);
char *join_3(char a[], char b[], char d[]);
char *mystrtok(char *s, char *d);
char **find_pathdir(char **arr);

#endif
