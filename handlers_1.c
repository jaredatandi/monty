#include "monty.h"
#include "errors.h"

/**
 * push_h - a function to push to either stack or queue
 * @stack: a struct with stack infor
 * @line_number: line number on the file
 */

void push_h(stack_t **stack, unsigned int line_number)
{
	int i, n = 0;
	stack_t *new;

	/** Check if any data is provided **/
	if (infor.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		release_all(1);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < infor.words[1][i]; i++)
	{
		/** Check for other ASCII chars**/
		if (isalpha(infor.words[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			release_all(1);
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(infor.words[1]);
	if (infor.flag == 0)
		new = add_top(stack, n);
	else if (infor.flag == 1)
		new = add_end(stack, n);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		release_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_h - handles the pall instruction
 * @stack: a struct pointer to the stack to push
 * @line_number: line number on the file
 */
void pall_h(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		p_list(*stack);
}
/**
 * pint_h - handles pint instruction
 * @stack: pointer to vector with stack
 * @line_number: line number on file
 */
void pint_h(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (!h)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		release_all(1);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}

/**
 * pop_h - handles the pop instruction
 * @stack: pointer to stack vector array
 * @line_number: line number on the file
 */
void pop_h(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		release_all(1);
		exit(EXIT_FAILURE);
	}

	delete_node(stack, 0);
}
