#include "monty.h"
#include "errors.h"


/**
 * mul_h - multiplication handling
 * @stack: pointer to the stack
 * @line_number: line number on the file
 * Description: mul function multiplies the second top element
 * of the stack with the top element of the stack
 */
void mul_h(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *node = NULL;
	stack_t *node_0, *node_1;

	if (list_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, line_number);
		release_all(1);
		exit(EXIT_FAILURE);
	}
	node_0 = get_node(*stack, 0);
	node_1 = get_node(*stack, 1);

	res = node_0->n * node_1->n;
	delete_node(stack, 0);
	delete_node(stack, 0);
	node = add_top(stack, res);

	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		release_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_h - 
 * @stac: pointer to the stack
 * @line_number: line number on file
 * Description: calculates the remainder of
 * div operation
 */
void mod_h(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *node, *node_0, *node_1;
	node = NULL;

	if (list_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		release_all(1);
		exit(EXIT_FAILURE);
	}

	node_0 = get_node(*stack, 0);
	node_1 = get_node(*stack, 1);

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		release_all(1);
		exit(EXIT_FAILURE);
	}
	
	res = node_1->n % node_0->n;
	node = add_top(stack, res); 
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		release_all(1);
		exit(EXIT_FAILURE);
	}
}
