#include "monty.h" 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
* push - pushes an element to the stack
* @stack: pointer to the stack struct
* @line_number: the current line number
*
* Description: an implementation of the push function to be
* used on a stack
*/

void push_h(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tmp;
	char *n = strtok(NULL, "\n \t");
	int *val;

	/** check if the input is an int **/
	if (!isdigit(n))
	{
		fprintf(stdout, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** convert the input to a number **/
	val = atoi(n[2]);
	new = malloc(sizeof(stack_t));

	/** return error if malloc failed **/
	if (new == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = val;
	new->prev = NULL;
	new->next = NULL;

	/** check if the stack is empty **/
	if ((*stack) == NULL)
		*stack = new;

	/** push to the top **/
	else if (LIFO)
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}

	/** push to the bottom **/
	else 
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
