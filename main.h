#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
int _putchar(char c);
int _printstring(char *str);
int len_str(char *);
int compare_strings(char *, char *);
char *begins_with(const char *, const char *);
char *join_strings(char *, char *);
/*void prompt();*/
#endif
