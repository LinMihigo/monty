#include "monty.h"

/**
 * _add - add the top two elements of the stack
 * @stack: The doubly linked list
 * @line_num: File line execution
 */
void _add(stack_t **stack, int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_num);
}

/**
 * _nop - doesn't do anythinhg
 *
 * @stack: head of the doubly linked list
 * @line_num: Current line number
 * Return: no return
 */
void _nop(stack_t **stack, int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * _sub - sub the first and second element in the stack
 * @stack: The doubly linked list
 * @line_num: Line counter
 */
void _sub(stack_t **stack, int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_num);
}

/**
 * _div - divide the first and second nodes in the stack
 * @stack: The doubly linked list
 * @line_num: Current line in file
 */
void _div(stack_t **stack, int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_num);
}

/**
 * _mul - Multiply the first and second nodes in the stack
 * @stack: The doubly linked list
 * @line_num: File line execution
 */
void _mul(stack_t **stack, int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	_pop(stack, line_num);
}
