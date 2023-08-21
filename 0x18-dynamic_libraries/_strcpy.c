#include "main.h"

/**
 * _strcpy - Copies the string pointed by src to dest
 * @dest: The destination buffer
 * @src: The source string
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	char *dest_ptr = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (dest_ptr);
}
