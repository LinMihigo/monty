#include "monty.h"
/**
 * pall - Print list
 * @stack: Double linked list
 * @line_num: File line execution
 */
void pall(stack_t **stack, int line_num)
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
 * push - Insert a new value in list
 * @stack: Double linked list
 * @line_num: File line execution
 */
void push(stack_t **stack, int line_num)
{
	stack_t *tmp = NULL, *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (is_integer(num) != 0 && num[0] != '-'))
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
 * pint - Print last node
 * @stack: Double linked list
 * @line_num: File line execution
 */
void pint(stack_t **stack, int line_num)
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
* pop - Delete top of list
* @stack: Double linked list
* @line_num: File line execution
*/
void pop(stack_t **stack, int line_num)
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
 * swap - Delete top of list
 * @stack: Double linked list
 * @line_num: File line execution
 */
void swap(stack_t **stack, int line_num)
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
