#include "errors.h"
#include "monty.h"

/**
 * get_func - returns the right function for the
 * opcode operation
 * @parsed: the parsed line from the bytecode file
 *
 * Return: a pointer to the function selected
 */

void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_h},
		{"pall", pall_h},
		{"pint", pint_h},
		{"pop", pop_h},
		{"swap", swap_h},
		{"add", add_h},
		{"nop", nop_h}
	};

	int funcs = 7, i;

	for (i = 0; i < funcs; ++i)
	{
		if (strcmp(func_arr[i].opcode, parsed[0]) == 0)
		{
			return (func_arr[i].f);
		}
	}
	return (NULL);
}

