#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, int line_num);
} instruction_t;

/**
 * struct globv_s - struct to hold global variables
 * @file: file to open
 * @line: buffer to hold the line of opcode
 * @line_len: line of opcode len
 * @dict: opcode - function reference object
 * @head: head node of the stack
 * @line_num: current line in file
 * @MODE: stack/Queue config
 *
 * Description: globv
 */
typedef struct globv_s
{
	FILE *file;
	char *line;
	size_t line_len;
	instruction_t *dict;
	stack_t *head;
	int line_num;
	int MODE;
} globv_t;

globv_t globv;

/* utils.c */
int globv_init(globv_t *globv);
instruction_t *opcode_handler(void);
int func_caller(globv_t *globv, char *opcode);
void free_globv(void);
int is_all_digits(char *string);

/* opcode_funcs.c */
void _pall(stack_t **stack, int line_num);
void _push(stack_t **stack, int line_num);
void _pint(stack_t **stack, int line_num);
void _pop(stack_t **stack, int line_num);
void _swap(stack_t **stack, int line_num);

/* opcode_funcs2.c */
void _add(stack_t **stack, int line_num);
void _nop(stack_t **stack, int line_num);
void _sub(stack_t **stack, int line_num);
void _div(stack_t **stack, int line_num);
void _mul(stack_t **stack, int line_num);

/* getline.c */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif /* MONTY_H */
