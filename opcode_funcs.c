#include "monty.h"
/**
 * _pall - Print the stack/queue
 * @stack: The doubly linked list
 * @line_num: Current line in file
 */
void _pall(stack_t **stack, int line_num)
{
	stack_t *tmp = *stack;
	(void) line_num;

	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _push - Insert a new value in the stack or queue
 * @stack: The doubly linked list
 * @line_num: Current line in file
 */
void _push(stack_t **stack, int line_num)
{
	stack_t *tmp = NULL, *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (is_all_digits(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	tmp->n = atoi(num);
	if (globv.MODE == 0 || !*stack)
	{
		tmp->next = *stack;
		tmp->prev = NULL;
		if (*stack)
			(*stack)->prev = tmp;
		*stack = tmp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = tmp;
		tmp->prev = tm;
		tmp->next = NULL;
	}
}

/**
 * _pint - Print the node inserted last
 * @stack: The doubly linked list
 * @line_num: Current line in file
 */
void _pint(stack_t **stack, int line_num)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* _pop - Delete an item form the top of the stack
* @stack: The doubly linked list
* @line_num: Current line in file
*/
void _pop(stack_t **stack, int line_num)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}


/**
 * _swap - Switch first and second nodes in the stack/queue
 * @stack: The doubly linked list
 * @line_num: Current line in file
 */
void _swap(stack_t **stack, int line_num)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
