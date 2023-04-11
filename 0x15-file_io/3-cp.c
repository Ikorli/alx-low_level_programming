#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - Allocates a buffer for reading from file.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == 0)
	{
		fprintf(stderr, "Error: Can't write to %s\n", file);
		exit(EXIT_FAILURE);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", fd);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	while (r > 0)
	{
		if (from == -1 || r == -1)
		{
			fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(EXIT_FAILURE);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(EXIT_FAILURE);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	}
	close_file(from);
	close_file(to);
	free(buffer);

	return (EXIT_SUCCESS);
}
