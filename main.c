#include "monty.h"

/**
* main - main func
* @ac: num of args received the monty executable
* @av: an array of arguments received
* Return: 0 - success
*/
int main(int ac, char **av)
{
	FILE *file;
	instruction_t list;

	/* TODO: Need to read file received as an arg to the exec */
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", av[1]);
	fclose(file);

	return (0);
}
