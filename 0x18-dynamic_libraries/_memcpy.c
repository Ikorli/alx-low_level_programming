#include "main.h"

/**
 * _memcpy - Copies memory area from src to dest
 * @dest: The destination memory area
 * @src: The source memory area
 * @n: The number of bytes to copy
 *
 * Return: Pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
