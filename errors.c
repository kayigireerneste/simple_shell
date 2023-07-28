#include "shell.h"
/**
 * _eputs - a function to prints an input string
 * @str: char parameter for the string to be printed
 * Return: nothing to return on void function
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}
/**
 * _eputchar - a function that writes the character c to stderr
 * @c: The char parameter for printing character
 * Return: return 1 on success and -1 on error
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * _putfd - a function to writes the character c to given fd
 * @c: The char parameter for character to print
 * @fd: an int parameter fot the filedescriptor to write to
 * Return: return 1 on success and -1 on error
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * _putsfd - a function that prints an input string
 * @str: a char parameter for string to be printed
 * @fd: an int parameter for the filedescriptor to write to
 * Return: returns the number of inputed char
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
