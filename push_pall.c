#include "structs.h"
#include "errors.h"
#include "lists.h"

void push_h(stack_t **stack, unsigned int line_number)
{
	int i;

	UNUSED(stack);

	if (infor.words[1] == NULL)
	{
		fprintf(stderr, PUSH_FAIL, line_number);
		release_all(1);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < infor.words[1][i]; ++i)
	{
		if (isalpha(infor.words[1][i]) != 0)
		{
			fprintf(stderr, PUSH_FAIL, line_number);
			release_all(1);
			exit(EXIT_FAILURE);
		}
	}

	if (infor.flag == 0)
		printf("add to stack\n");
	else if (infor.flag == 1)
		printf("add to end");
}

