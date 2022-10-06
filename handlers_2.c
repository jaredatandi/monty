#include "monty.h"
#include "errors.h"

/**
 * swap_h - handles the swap instructions
 * @stack: a vector pointer to the stack
 * @line_number: line number on the file
 */
void swap_h(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *node = NULL;
	int num;

	if (list_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_number);
		release_all(10);
		exit(EXIT_FAILURE);
	}

	tmp = get_node(*stack, 0);
	num = tmp->n;
	delete_node(stack, 0);
	node = insert_node(stack, 1, num);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		release_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * add_h - handles the add instruction
 * @stack: pointer to stack
 * @line_number: line number on the file
 */
void add_h(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_node(*stack, 0);
	stack_t *node_1 = get_node(*stack, 1);

	if (list_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_number);
		release_all(1);
		exit(EXIT_FAILURE);
	}

	sum = node_0->n + node_1->n;
	delete_node(stack, 0);
	delete_node(stack, 0);
	node = add_top(stack, sum);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		release_all(1);
		exit(EXIT_FAILURE);
	}
}
/**
 * nop_h - handles the nop instruction
 * @stack: pointer to the stack
 * @line_number: line number on the file
 */
void nop_h(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
