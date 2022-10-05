#include "structs.h"
#include "errors.h"
#include <stdio.h>

#define OK 1
#define NO 0

void run_cmd(int ac, char *av)
{
	size_t flag = 0;
	char *line;
	size_t len = 0;
	FILE *fptr;
	int sts = OK;

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

	while (sts)
	{
		flag = getline(&line, &len, fptr);
		if (flag <= 0)
		{
			fprintf(stderr, "getline");
			exit(EXIT_FAILURE);
		}
		sts = NO;
		printf("That was a success");
	}
}


int main(int argc, char **argv)
{
	int ac = argc;
	char **av = argv;

	run_cmd(ac, av[1]);
	return 0;
}
