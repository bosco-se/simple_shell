#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, const char *src)
{
    char *ret = dest;

    if (dest == src || src == NULL)
        return (dest);

    while (*src)
        *dest++ = *src++;
    *dest = '\0';

    return (ret);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
    char *dup_str;
    size_t len;

    if (str == NULL)
        return (NULL);

    len = _strlen(str);
    dup_str = malloc(sizeof(char) * (len + 1));

    if (dup_str == NULL)
        return (NULL);

    _strcpy(dup_str, str);
    return (dup_str);
}

/**
 * _puts - prints a string to stdout
 * @str: the string to print
 *
 * Return: Nothing
 */
void _puts(const char *str)
{
    if (str != NULL)
        write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    static char buf[WRITE_BUF_SIZE];
    static int pos;

    if (c == BUF_FLUSH || pos >= WRITE_BUF_SIZE)
    {
        write(STDOUT_FILENO, buf, pos);
        pos = 0;
    }
    if (c != BUF_FLUSH)
        buf[pos++] = c;

    return (1);
}
