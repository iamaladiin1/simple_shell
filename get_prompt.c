#include "main.h"

/**
 * prompt - Prints the shell prompt.
 *
 * Return: void.
 */
void prompt(void)
{
    write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}

