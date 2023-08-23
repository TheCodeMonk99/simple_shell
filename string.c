#include "main.h"

/**
 * len_str - Calculates the length of a provided string.
 * @str: Pointer to the string.
 *
 * Return: Number of characters in the string excluding the null terminator.
 */
int len_str(char *str)
{
	int count = 0;

	if (!str)
		return (0);

	while (str[count])
		count++;
	return (count);
}

/**
 * compare_strings - Compares two strings lexicographically.
 * @strA: The first string.
 * @strB: The second string.
 *
 * Return:
 * - Negative value if strA < strB,
 * - Positive value if strA > strB,
 * - 0 if strA is equal to strB.
 */
int compare_strings(char *strA, char *strB)
{
	while (*strA && *strB)
	{
		if (*strA != *strB)
			return (*strA - *strB);
		strA++;
		strB++;
	}
	if (*strA == *strB)
		return (0);
	else
		return (*strA < *strB ? -1 : 1);
}

/**
 * begins_with - Checks if the main_str starts with sub_str.
 * @main_str: The main string to be checked.
 * @sub_str: The substring to be matched.
 *
 * Return: Address of next character in main_str after the sub_str,
 *         or NULL if main_str doesn't start with sub_str.
 */
char *begins_with(const char *main_str, const char *sub_str)
{
	while (*sub_str)
		if (*sub_str++ != *main_str++)
			return (NULL);
	return ((char *)main_str);
}

/**
 * join_strings - Joins two strings together.
 * @buffer: The destination buffer.
 * @addition: The source buffer to be added.
 *
 * Return: Pointer to the combined string in the destination buffer.
 */
char *join_strings(char *buffer, char *addition)
{
	char *initial = buffer;

	while (*buffer)
		buffer++;
	while (*addition)
		*buffer++ = *addition++;
	*buffer = *addition;
	return (initial);
}
/**
 * link_paths - links a directory, slash character and argument string
 * @directory: directories
 * @slash: /
 * @arg: argument string to link
 * Return: str
 **/
char *link_paths(char *directory, char *slash, char *arg)
{
	char *str = NULL;
	int l1, l2, i, k;
	
	/* calculate length of input string */
	l1 = _strlen(directory);
	l2 = _strlen(arg);
	/* allocates memory to linked string */
	str = malloc(sizeof(char) * (l1 + l2 + 2));
	if (!str)
		return (NULL);
	/* copy directory to new string */
	for (i = 0; directory[i]; i++)
		str[i] = directory[i];
	/* add slash charcter to new string */
	str[i] = *slash;
	k = i + 1;
	/*copy argument string to new string*/
	for (i = 0; arg[i]; i++)
		str[k + i] = arg[i];
	/*add null terminator to new string*/
	str[k + i] = '\0';
	return (str);
}
