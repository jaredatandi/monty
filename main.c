#include "structs.h"
#include "errors.h"
#include "lists.h"

#include <stdio.h>

void run_cmd(args_a *args)
{

	int flag = 0;
	size_t len = 0;
	void (*func)(stack_t **, unsigned int);

	/*void (*func)(stack_t **, unsigned int);*/

	if (args->ac != 2)
	{
		fprintf(stderr, USAGE);
		exit(EXIT_FAILURE);
	}

	infor.file = fopen(args->file, "r");
	if (!infor.file)
	{
		fprintf(stderr, FILE_ERROR, args->file);
	}

	while (1)
	{
		args->line_number++;
		flag = getline(&(infor.line), &len, infor.file);
		if (flag < 0)
			break;
		infor.words = tokens(infor.line);
		if (infor.words[0] == NULL || infor.words[0][0] == '#')
		{
			release_all(0);
			continue;
		}
		func = get_func(infor.words);
		if (!func)
		{
			fprintf(stderr, UNKNOWN, args->line_number, infor.words[0]);
			release_all(1);
			exit(EXIT_FAILURE);
		}
		func(&(infor.stack), args->line_number);
		release_all(0);
	}
	release_all(1);
}


int main(int argc, char **argv)
{

	args_a args;
	
	args.ac = argc;
	args.file = argv[1];
	args.line_number = 0;

	run_cmd(&args);
	return 0;
}
