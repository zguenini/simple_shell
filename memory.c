#include "shell.h"

/**
 * Function to free a pointer and NULL the address.
 *
 * @param ptr Address of the pointer to free
 * @return 1 if freed, otherwise 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
