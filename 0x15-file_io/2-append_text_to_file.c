#include "main.h"
#include <stdio.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: 1 on success, -1 on failure or if filename is NULL.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	if (filename == NULL)
		return (-1);

	int fd, w, len = 0;

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	w = write(fd, text_content, len);
	if (w == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
