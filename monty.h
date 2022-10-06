#ifndef LISTS_H
#define LISTS_HLISTS_H

#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


/** Structs **/

/**
 * struct stack_s - doubly linked list represenation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef	struct args
{
	int ac;
	char *file;
	unsigned int line_number;
} args_a;

typedef struct infr
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *file;
	int flag;
} infor_s;

extern infor_s infor;

#define INFOR_INIT {NULL, NULL, NULL, NULL, 0}

void push_h(stack_t **stack, unsigned int line_number);
int count_ws(char *str);
char **tokens(char *str);
void run_cmd(args_a *args);
void (*get_func(char **parse))(stack_t **, unsigned int);
void release(char **args);
void release_all(int all);
void free_stack(char *stack);


#endif /* end of include guard: STRUCTS_H*/
