#include "main.h"
#include <stdlib.h>
/**
 * read_textfile - Reads and prints the contents of a file.
 * @filename: Name of the file to be read.
 * @letters: Number of bytes to be read and printed.
 *
 * Return: The number of bytes read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(fd);
		return (0);
	}

	bytes_read = read(fd, buffer, letters);
	close(fd);
	if (bytes_read == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	free(buffer);
	if (bytes_written == -1 || bytes_written != bytes_read)
		return (0);

	return (bytes_written);
}
