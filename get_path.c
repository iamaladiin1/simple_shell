#include "main.h"

/**
 * get_path - Returns the value of the PATH environment variable.
 *
 * Return: Pointer to the value of the PATH variable.
 */
char *get_path(void)
{
    return (_getenv("PATH"));
}

