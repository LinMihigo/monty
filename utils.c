#include "monty.h"

/**
* globv_init - glob variables initializer
* @globv: Global variable
* Return: 0 - success | 1 - failure
*/
int globv_init(globv_t *globv)
{
	globv->file = NULL;
	globv->line = NULL;
	globv->line_len = 0;
	globv->dict = opcode_handler();
	if (globv->dict == NULL)
		return (1);
	globv->line_num = 1;
	globv->MODE = 0;

	return (0);
}
/**
* opcode_handler - create a reference which func to call given an opcode
* Return: the struct instruct_t
*/
instruction_t *opcode_handler(void)
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	ptr[0].opcode = "pall", ptr[0].f = pall;
	ptr[1].opcode = "push", ptr[1].f = push;
	ptr[2].opcode = "pint", ptr[2].f = pint;
	ptr[3].opcode = "pop", ptr[3].f = pop;
	ptr[4].opcode = "swap", ptr[4].f = swap;

	return (ptr);
}

/**
* func_caller - calls the respective func for an opcode
* @globv: the global var struct
* @opcode: opcode currently being processed
* Return: int
*/
int func_caller(globv_t *globv, char *opcode)
{
	int i;

	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", globv->line_num, opcode);
		return (1);
	}

	for (i = 0; globv->dict[i].opcode; i++)
	{
		if (strcmp(opcode, globv->dict[i].opcode) == 0)
		{
			if (!globv->dict[i].f)
				return (0);
			globv->dict[i].f(&globv->head, globv->line_num);
			return (0);
		}
	}
	return (0);
}

/**
* free_globv - free allocated memory in glob var
* Return: void
*/
void free_globv(void)
{
	if (globv.line)
		free(globv.line);
	if (globv.file)
		fclose(globv.file);
	free(globv.dict);
	if (globv.head)
	{
		while (globv.head->next)
		{
			globv.head = globv.head->next;
			free(globv.head->prev);
		}
		free(globv.head);
	}
}

/**
* is_integer - check if isdigit
* @str: string to check
* Return: 0 - Success | 1 - Failure
*/
int is_integer(const char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
