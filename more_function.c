#include "shell.h"
/**
 * Function to copy source to destination.
 *
 * @param dest Destination
 * @param src Source
 * @return Copy of char *
 */
char *_strcpy(char *dest, char *src)
{
int i;

i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
dest[i] = '\0';
return (dest);
}
/**
 * Function to concatenate two strings and run.
 *
 * @param dest First String
 * @param src Second String
 * @return First String + Second String (Char *)
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * Function to locate a character in a string.
 *
 * @param s String to search in
 * @param c Character to search for
 * @return Pointer to char *
 */
char *_strchr(char *s, char c)
{

	do		{

		if (*s == c)
			{
			break;
			}
		}	while (*s++);

return (s);
}
/**
 * Function to compare a specified amount (n) of characters in two strings.
 *
 * @param s1 A String
 * @param s2 A String
 * @param n Amount of characters to compare
 * @return 1 if the strings don't match, otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * Function to duplicate a string and run.
 *
 * @param str String
 * @return Duplicate string, failed (NULL)
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}
