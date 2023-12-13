#include "shell.h"

/**
 * Function to return the length of a string.
 *
 * @param s The string whose length to check
 * @return Integer length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * Function to perform lexicographic comparison of two strings.
 *
 * @param s1 The first string
 * @param s2 The second string
 * @return Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * Function to check if needle starts with haystack.
 *
 * @param haystack The string to search
 * @param needle The substring to find
 * @return Address of the next character of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * Function to concatenate two strings.
 *
 * @param dest The destination buffer
 * @param src The source buffer
 * @return Pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
