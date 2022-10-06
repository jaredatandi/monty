#include "structs.h"
#include "errors.h"
#include "lists.h"

void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_h},
	};

	int funcs = 1, i;

	for (i = 0; i < funcs; ++i)
	{
		if (strcmp(func_arr[i].opcode, parsed[0]) == 0)
		{
			return (func_arr[i].f);
		}
	}
	return (NULL);
}

