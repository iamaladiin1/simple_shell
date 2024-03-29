#include "main.h"
#include <stddef.h> 

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
size_t _strlen(const char *s)
{
    size_t i = 0;

    if (!s)
        return 0;

    while (*s++)
        i++;
    return i;
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: 0 if @s1 and @s2 are equal,
 *         a negative value if @s1 is less than @s2,
 *         or a positive value if @s1 is greater than @s2.
 */
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    return (int)(*s1) - (int)(*s2);
}

/**
 * _strncmp - Compare two strings up to a specified length.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 * @n: Maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal up to n characters, negative value
 *         if s1 is less than s2, or positive value if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char c1, c2;

    while (n-- > 0)
    {
        c1 = (unsigned char)*s1++;
        c2 = (unsigned char)*s2++;

        if (c1 != c2)
            return (int)(c1 - c2);
        if (c1 == '\0')
            break;
    }

    return 0;
}

/**
 * _strstr - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *_strstr(const char *haystack, const char *needle)
{
    size_t i, j;

    for (i = 0; haystack[i] != '\0'; i++)
    {
        if (haystack[i] == needle[0])
        {
            for (j = 0; needle[j] != '\0'; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }

            if (needle[j] == '\0')
            {
                return (char *)&haystack[i];
            }
        }
    }
    return NULL;
}

/**
 * _strchr - a function that locates a character in a string
 *
 * @s: pointer to our string array input
 * @c: character to locate from input array
 *
 * Return: first occurrence of character or NULL if not found
 */
char *_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (char *)s;
        s++;
    }
    /**
     * If c is '\0', you should return
     * the pointer to the '\0' of the
     * string s
     */
    if (*s == c)
        return (char *)s;
    /* Return NULL if not found */
    return NULL;
}

