#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the amount of characters to be copied
 * Return: the copied string, or NULL if allocation fails
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	char *cpy = NULL;
	size_t len = 0;

	if (!src || !dest)
		return (NULL);

	len = _strlen(src);
	if (n < len)
		len = n;

	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);

	_memcpy(cpy, src, len);
	cpy[len] = '\0';

	_memcpy(dest, cpy, len + 1);
	free(cpy);

	return (dest);
}

/**
 * _strncat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string, or NULL if allocation fails
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	char *cat = NULL;
	size_t dest_len = 0, src_len = 0, len = 0;

	if (!src || !dest)
		return (NULL);

	dest_len = _strlen(dest);
	src_len = _strlen(src);
	if (n < src_len)
		src_len = n;

	len = dest_len + src_len;
	cat = malloc(sizeof(char) * (len + 1));
	if (!cat)
		return (NULL);

	_memcpy(cat, dest, dest_len);
	_memcpy(cat + dest_len, src, src_len);
	cat[len] = '\0';

	_memcpy(dest, cat, len + 1);
	free(cat);

	return (dest);
}

/**
 * _strchr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 * Return: a pointer to the located character, or NULL if not found
 */
char *_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);

	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}

	return (NULL);
}
