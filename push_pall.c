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
		fprintf(stderr, PUSH_FAIL, line_number);
		release_all(1);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < infor.words[1][i]; i++)
	{
		/** Check for other ASCII chars other than
		 * Words and numbers **/
		if (isalpha(infor.words[1][i]) != 0)
		{
			fprintf(stderr, PUSH_FAIL, line_number);
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
		fprintf(stderr, MALLOC_FAIL);
		release_all(1);
		exit(EXIT_FAILURE);
	}
}

