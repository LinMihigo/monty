#include "monty.h"
/**
* _getline - custom getline func
* @lineptr: buffer to hold the line to be read
* @n: line length
* @stream: stream to read from
* Return: size of the line read
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((c = fgetc(stream)) != -1)
	{
		if (pos + 1 >= *n)
		{
			free(*lineptr);
			*lineptr = NULL;
			return (-1);
		}
		(*lineptr)[pos++] = c;
		if (c == '\n')
			break;
	}
	if (pos == 0 && c == EOF)
		return (-1);
	(*lineptr)[pos] = '\0';
	return (pos);
}
