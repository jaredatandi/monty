#include "monty.h"
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

infor_s infor = INFOR_INIT;

/**
 * run_cmd - a helper function to main
 * @args: a struct pointer to arguements from main
 */

void run_cmd(args_a *args)
{

	int flag = 0;
	size_t len = 0;
	void (*func)(stack_t **, unsigned int);

	/** Check if there is an arguement **/
	if (args->ac != 2)
	{
		fprintf(stderr, USAGE);
		exit(EXIT_FAILURE);
	}

	/** Attempt to open the argument, update error if not file **/
	infor.file = fopen(args->file, "r");
	if (!infor.file)
	{
		fprintf(stderr, FILE_ERROR, args->file);
	}

	while (1)
	{
		args->line_number++;
		/** Read one line in the file **/
		flag = getline(&(infor.line), &len, infor.file);
		if (flag < 0)
			break;
		infor.words = tokens(infor.line);
		if (infor.words[0] == NULL || infor.words[0][0] == '#')
		{
			release_all(0);
			continue;
		}

		/** Get the handler function, update error if
		 * opcode is unknown **/
		func = get_func(infor.words);
		if (!func)
		{
			fprintf(stderr, UNKNOWN, args->line_number, infor.words[0]);
			release_all(1);
			exit(EXIT_FAILURE);
		}
		/** Pass the read data to the handler **/
		func(&(infor.stack), args->line_number);
		release_all(0);
	}
	release_all(1);
}
/**
 * main - the entry point to the program
 * @argc: argument count
 * @argv: vector array of the arguments
 * Return: 0 success, 1 otherwise
 */

int main(int argc, char **argv)
{
	args_a args;

	args.ac = argc;
	args.file = argv[1];
	args.line_number = 0;
	run_cmd(&args);

	return (0);
}
