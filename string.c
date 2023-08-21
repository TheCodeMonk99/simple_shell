#include "main.h"

/**
 * custom_strlen - returns the length of a string
 * @str: the string whose length to calculate
 *
 * Return: integer length of the string
 */
int custom_strlen(char *str)
{
    int length = 0;

    if (!str)
        return 0;

    while (*str++)
        length++;
    return length;
}

/**
 * custom_strcmp - performs lexicographic comparison of two strings.
 * @str1: the first string
 * @str2: the second string
 *
 * Return: negative if str1 < str2, positive if str1 > str2, zero if str1 == str2
 */
int custom_strcmp(char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    if (*str1 == *str2)
        return 0;
    else
        return (*str1 < *str2 ? -1 : 1);
}

/**
 * custom_starts_with - checks if prefix starts with main_string
 * @main_string: the main string to search within
 * @prefix: the prefix to find
 *
 * Return: address of next character in main_string after the prefix, or NULL
 */
char *custom_starts_with(const char *main_string, const char *prefix)
{
    while (*prefix)
        if (*prefix++ != *main_string++)
            return NULL;
    return (char *)main_string;
}

/**
 * custom_strcat - concatenates two strings
 * @destination: the destination buffer
 * @source: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *custom_strcat(char *destination, char *source)
{
    char *result = destination;

    while (*destination)
        destination++;
    while (*source)
        *destination++ = *source++;
    *destination = *source;
    return result;
}
