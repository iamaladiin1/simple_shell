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



void shell_help(void);
void _puterror(const char *msg);
void _puts(const char *msg);
void prompt();
void free_error(char **argv, char *arg);
void free_tokens(char **ptr);
void free_path(void);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *, char *);
char *_strcat(char *, const char *);
void shell_exit(char **args);
void shell_cd(char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);
void prompt(void);
char *get_input(void);
void free_last_input(void);
void *get_line(void);
int check_for_builtin(char **args);
int execute_buitlin(char *cmd, char **args);
int shell_env(void);
int shell_clear(char **args);
void handle_sigint(int sig);
void handle_sigquit(int sig);
void handle_sigstp(int sig);
int execute(char **args);
char **tokenize(char *str, const char *delim);
char **tokenize_input(char *input);
char *_getenv(const char *name);
char *get_path(void);
char *find_in_path(char *command);

char *_strdup(const char *);
int _putchar(char);
unsigned int _strspn(char *s, char *accept);
int _atoi(const char *str);
char *_memset(char *, char, unsigned int);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int nmemb, unsigned int size);

#endif
