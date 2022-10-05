#include "structs.h"
#include "errors.h"
#include <stdio.h>

void run_cmd(int ac, char *av, int line_number)
{
	int flag = 0;
	char *line;
	size_t len = 0;
	FILE *fptr;

	UNUSED(line_number);

	/*void (*func)(stack_t **, unsigned int);*/

	if (ac != 2)
	{
		fprintf(stderr, USAGE);
		exit(EXIT_FAILURE);
	}

	fptr = fopen(av, "r");
	if (!fptr)
	{
		fprintf(stderr, FILE_ERROR, av);
	}

	while (1)
	{
		flag = getline(&line, &len, fptr);
		if (flag < 0)
			break;

	}
}


int main(int argc, char **argv)
{
	int ac = argc, line_number = 0;
	char **av = argv;

	run_cmd(ac, av[1], line_number);
	return 0;
}
