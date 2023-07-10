#include "main.h"
#include <stdio.h>

/**
 * create_file - Creates a file and writes content to it.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	if (filename == NULL)
		return (-1);

	FILE *file = fopen(filename, "w");

	if (file == NULL)
		return (-1);

	if (text_content != NULL)
		fputs(text_content, file);

	fclose(file);
	return (1);
}
