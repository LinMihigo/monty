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
	char line[128];

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		printf("%s\n", line);
	}
	
	return (0);
}
