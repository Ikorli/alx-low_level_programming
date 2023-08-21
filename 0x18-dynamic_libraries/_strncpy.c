#include "main.h"

/**
 * _strncpy - Copies up to n bytes from src to dest
 * @dest: The destination buffer
 * @src: The source string
 * @n: The number of bytes to copy
 *
 * Return: Pointer to dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
