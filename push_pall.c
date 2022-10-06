#include "monty.h"
#include "errors.h"

extern infor_s infor;

void push_h(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	int i;


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

