#include "monty.h"

/**
* main - main func
* @ac: num of args received the monty executable
* @av: an array of arguments received
* Return: 0 - success
*/
int main(int ac, char **av)
{
	char *opcode;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (globv_init(&globv) != 0)
		return (1);

	globv.file = fopen(av[1], "r");
	if (!globv.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free_globv();
		exit(EXIT_FAILURE);
	}

	while (_getline(&globv.line, &globv.line_len, globv.file) != -1)
	{
		opcode = strtok(globv.line, " \t\n");

		if (opcode)
		{
			if (func_caller(&globv, opcode) == 1)
			{
				free_globv();
				return (1);
			}
		}
		globv.line_num++;
	}

	free_globv();

	return (0);
}
