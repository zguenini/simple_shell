#include "shell.h"

/**
 * Function to print a character to stdout.
 *
 * @param c The character to print
 * @return On success 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * Function to copy a string and paste up to the specified number of characters.
 *
 * @param dest Destination character array
 * @param src Source character array
 * @param n Number of characters to copy
 * @return char
 */

char *_strncpy(char *dest, char *src, int n)
{
int i;

i = 0;
	while (i < n && *(src + i))
	{
	*(dest + i) = *(src + i);
	i++;
	}
	while (i < n)
	{
	*(dest + i) = '\0';
	i++;
	}
	return (dest);
}

/**
 * Function to calculate the length of a string.
 *
 * @param s Character array (string)
 * @return Length of the string (int)
 */

int _strlen(char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}

/**
 * Function to convert a string to an integer.
 *
 * @param s String to convert
 * @return Integer representation of the string
 */
int _atoi(char *s)
{
int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}
/**
 * Function to print a string of characters.
 *
 * @param str Pointer to a character array
 * @return void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
_putchar('\n');
return;
}
