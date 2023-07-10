#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: Name of the text file to be read.
 * @letters: Number of letters to be read.
 * Return: Actual number of bytes read and printed.
 * 0 on failure or if filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	FILE *file = fopen(filename, "r");

	if (file == NULL)
		return (0);

	char *buf = malloc(sizeof(char) * (letters + 1));

	if (buf == NULL)
	{
		fclose(file);
		return (0);
	}

	ssize_t t = fread(buf, sizeof(char), letters, file);
	ssize_t w = fwrite(buf, sizeof(char), t, stdout);

	free(buf);
	fclose(file);

	return (w);
}
