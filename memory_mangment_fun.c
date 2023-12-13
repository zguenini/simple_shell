#include "shell.h"

/**
 * Function to reallocate a memory block.
 *
 * @param ptr Pointer
 * @param old_size Previous size of the pointer
 * @param new_size New size of the pointer
 * @return Void pointer to the reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);

}
/**
 * Function to free an array and a character pointer.
 *
 * @param cmd Array Pointer
 * @param line Character Pointer
 * @return Void
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * Function to copy a specified number of bytes from source to destination.
 *
 * @param dest Destination Pointer
 * @param src Source Pointer
 * @param n Size (How much to copy)
 * @return Void Pointer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * Function to fill an array with a specified element.
 *
 * @param a Void Pointer
 * @param el Int
 * @param len Length Int
 * @return Void Pointer
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * Function to allocate memory for an array.
 *
 * @param size Size
 * @return Void Pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
