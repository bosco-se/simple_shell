#include "shell.h"

/**
 * _eputs - prints an input string to stderr
 * @str: the string to be printed
 *
 * Return: nothing
 */
void _eputs(char *str)
{
	if (!str)
		return;

	while (*str)
		_eputchar(*str++);
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int buf_idx;

	if (c == BUF_FLUSH || buf_idx >= WRITE_BUF_SIZE)
	{
		write(STDERR_FILENO, buf, buf_idx);
		buf_idx = 0;
	}

	if (c != BUF_FLUSH)
		buf[buf_idx++] = c;

	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static char buf[WRITE_BUF_SIZE];
	static int buf_idx;

	if (c == BUF_FLUSH || buf_idx >= WRITE_BUF_SIZE)
	{
		write(fd, buf, buf_idx);
		buf_idx = 0;
	}

	if (c != BUF_FLUSH)
		buf[buf_idx++] = c;

	return (1);
}

/**
 *_putsfd - prints an input string to given fd
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of characters put
 */
int _putsfd(char *str, int fd)
{
	int count = 0;

	if (!str)
		return (count);

	while (*str)
	{
		count += _putfd(*str++, fd);
	}

	return (count);
}
