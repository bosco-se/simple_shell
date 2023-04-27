#include "shell.h"

/**
 * bfree - frees a pointer and sets it to NULL
 * @ptr: pointer to the pointer to free
 *
 * Return: 1 if the pointer was freed, 0 otherwise.
 */
int bfree(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return 1;
    }
    return 0;
}
