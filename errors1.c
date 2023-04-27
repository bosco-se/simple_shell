#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: the integer value of the string, or -1 on error
 */
int _erratoi(char *s)
{
    int i;
    unsigned long result = 0;

    if (*s == '+')
        s++;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result = result * 10 + (s[i] - '0');
            if (result > INT_MAX)
                return (-1);
        }
        else
            return (-1);
    }

    return ((int)result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 */
void print_error(info_t *info, char *estr)
{
    _eputs(info->fname);
    _eputs(": ");
    print_d(info->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(info->argv[0]);
    _eputs(": ");
    _eputs(estr);
}

/**
 * print_d - prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
    int (*putchar_func)(char) = fd == STDERR_FILENO ? _eputchar : _putchar;
    int i, count = 0;
    unsigned int abs_input, current;

    if (input < 0)
    {
        abs_input = -input;
        putchar_func('-');
        count++;
    }
    else
    {
        abs_input = input;
    }

    current = abs_input;

    for (i = 1000000000; i > 1; i /= 10)
    {
        if (abs_input / i)
        {
            putchar_func('0' + current / i);
            count++;
        }

        current %= i;
    }

    putchar_func('0' + current);
    count++;

    return (count);
}

/**
 * convert_number - converts a number to a string in the specified base
 * @num: the number to convert
 * @base: the base to use for the conversion
 * @flags: flags that modify the output format
 *
 * Return: a string representing the converted number
 */
char *convert_number(long int num, int base, int flags)
{
    static char buffer[50];
    char *array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
    char sign = 0;
    char *ptr;
    unsigned long n = (num < 0 && !(flags & CONVERT_UNSIGNED)) ? -num : num;

    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (num < 0 && !(flags & CONVERT_UNSIGNED))
    {
        sign = '-';
    }
    else if (flags & CONVERT_PLUS)
    {
        sign = '+';
    }
    else if (flags & CONVERT_SPACE)
    {
        sign = ' ';
    }

    if (sign)
    {
        *--ptr = sign;
    }

    return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
