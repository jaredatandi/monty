#include <stddef.h>
#include "errors.h"
#include "monty.h"

/**
 * release - frees a malloced list
 * @args: a vector array of arguments
 */

void release(char **args)
{
	int i;

	if (!args)
		return;
	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}

/**
 * release_all - frees a list or queue
 * @all: a flag to determine what to free
 */

void release_all(int all)
{
	if (infor.line)
	{
		free(infor.line);
		infor.line = NULL;
		release(infor.words);
		infor.words = NULL;
	}

	if (all)
	{
		if (infor.stack)
		{
			infor.stack = NULL;
		}
		if (infor.file)
		{
			fclose(infor.file);
			infor.file = NULL;
		}
	}
}

