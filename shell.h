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
char **parse_str(char *str);
void _execute(char **arg, char **argv, char **env);
int _bexit(void);
int _benv(void);
int check_builtin(char **arr);
int char_counter(char *str, char c);
char *join_3(char a[], char b[], char d[]);
char *mystrtok(char *s, char *d);
void _find_pathdir(char **arr, char **argv, char **env);

#endif
