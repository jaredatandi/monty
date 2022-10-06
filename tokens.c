#include "monty.h"
#include "errors.h"

int count_ws(char *str)
{
	int count, w, flag;

	flag = 0;
	w = 0;

	for (count = 0; str[count] != '\0'; count++)
	{
		if (str[count] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}
	return (w);
}

char **tokens(char *str)
{
	char **av, *tmp;
	int i, k = 0, len = 0, c = 0, w, start, end;

	len = strlen(str);
	w = count_ws(str);
	if (w == 0)
		return (NULL);

	av = (char **) malloc(sizeof(char *) * (w + 1));
	if (av == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				av[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}
	av[k] = NULL;

	return (av);
}
