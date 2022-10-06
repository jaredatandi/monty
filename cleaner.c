#include <stddef.h>
#include "structs.h"
#include "errors.h"
#include "lists.h"

void release(char **args)
{
	int i;

	if (!args)
		return;
	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}


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

