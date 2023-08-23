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
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>
#ifndef BUFF_SIZE
#define BUFF_SIZE 1024
#endif
/**
  * struct link - node that contains directory
  * @dir: dirs
  * @next: address to the next node
  */
typedef struct link
{
	char *dir;
	struct link *next;
} link_t;
extern char **environ;
char *execute_command(char *argm);
int _printf(const char *format, ...);
int execute_process(char **argm, char **argv, int counter);
link_t *_add_nodeint_end(link_t **head, char *n);
size_t _print_listint(link_t *h);
/*strings*/
int _putchar(char c);
int _printstring(char *str);
int len_str(char *);
int compare_strings(char *, char *);
char *begins_with(const char *, const char *);
char *join_strings(char *, char *);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, char *delim);
char *check_path(char *argm);

int _getchar(void);
char *link_paths(char *directory, char *slash, char *arg);
int _strlen(char *s);
int p_aux_int(long int n, long int);
int p_str(va_list arguments);
char *_strtok(char *str, char *delim);
ssize_t _getline(char **bufline, size_t *size, FILE *std);
int p_char(va_list arguments);
int p_int(va_list arguments);
char *_getenv(const char *name);
char **splitline(char *command_line);
void signal_c(int sign);
link_t *_link(char *a);

char *_which(link_t **head, char *av);
void free_list(link_t *head);

/*prompt user*/
void prompt(void);

/*builtin.c*/
int _mexit(char *line);
void signal_c(int sign);
int _env(char *cmd, int counter, char **argv, char **env);

/*path*/
char *check_path(char *am);
char *execute_command(char *am);
/**
  * struct formats - formats
  * @ch: first element pointer
  * @func: function
  */
typedef struct formats
{
	char *ch;
	int (*func)();
} form;

#endif
