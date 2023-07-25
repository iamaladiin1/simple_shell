#ifndef  _MAIN_H_
#define  _MAIN_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>
#include <limits.h>



/*macros*/
#define PATH_MAX_LENGTH 1024
#define PATH_SEPARATOR ":"
#define PROMPT "$"
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

/* get_prompt.c */
void prompt(void);

/* get_input.c */
char *get_input(void);
void free_last_input(void);

/* get_line.c*/
void *get_line(void);

/* built-in func */
int check_for_builtin(char **args);
int execute_buitlin(char *cmd, char **args);
void shell_help(void);
void shell_exit(char **args);
void shell_cd(char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);
int shell_env(void);
int shell_clear(char **args);

/* signal_handler.c */
void handle_sigint(int sig);
void handle_sigquit(int sig);
void handle_sigstp(int sig);

/* execute.c */
int execute(char **args);

/* parser.c */
char **tokenize(char *str, const char *delim);
char **tokenize_input(char *input);

/* get_env.c */
char *_getenv(const char *name);

/* get_path.c */
char *get_path(void);

/* find_in_path.c */
char *find_in_path(char *command);

/* free.c */
void free_error(char **argv, char *arg);
void free_tokens(char **ptr);
void free_path(void);

/* errors.c */
void _puts(char *str);
void _puterror(char *err);

/* funcs1.c */
int _strlen(const char *);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *s, char c);

/* funcs2.c */
char *_strcpy(char *, char *);
char *_strcat(char *, const char *);
char *_strdup(const char *);
int _putchar(char);
unsigned int _strspn(char *s, char *accept);

/* funcs3.c */
int _atoi(const char *str);
char *_memset(char *, char, unsigned int);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int nmemb, unsigned int size);

#endif
