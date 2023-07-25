#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * _puts - Prints a string to the standard output stream
 * @str: The string to print
 *
 * Return: Void
 */
void _puts(const char *str)
{
    size_t len = _strlen(str);
    ssize_t num_written = write(STDOUT_FILENO, str, len);

    if (num_written == -1)
    {
        perror("write");
    }
}

/**
 * _puterror - Prints an error message to the standard error stream
 * @err: The error message to print
 *
 * Return: Void
 */
void _puterror(const char *err)
{
    size_t len = _strlen(err);
    ssize_t num_written = write(STDERR_FILENO, err, len);

    if (num_written == -1)
    {
        perror("write");
    }
}

