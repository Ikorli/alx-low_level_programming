#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: Pointer to a string containing the binary number
 *
 * Return: The converted number, or 0 if an error occurred
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == 0)
		return (0);

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0);

		result <<= 1;
		result += (*b - '0');
		b++;
	}

	return (result);
}
