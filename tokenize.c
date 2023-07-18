 #include "simple_shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * tokenize - tokenizes the string in the buffer
 * @buf: buffer containing text from stdin
 * Return: Pointer to tokenized strings
 */

char **tokenize(char **buf)
{
	int init_cap, seg_count;
	char *token;
	char **segments;
	char dl[] = " \t\n";

	init_cap = 10;
	seg_count = 0;
	segments = malloc(sizeof(char *) * init_cap);
	if (segments == NULL)
	{
	}
	token = strtok((*buf), dl);
	while (token != NULL)
	{
		if (seg_count >= init_cap)
		{
			init_cap *= 1.5;
			segments = realloc(segments, sizeof(char *) * init_cap);
		}
		segments[seg_count] = strdup(token);
		printf("%s\n", token);
		seg_count++;
		token = strtok(NULL, dl);
	}
	segments[seg_count] = NULL;
	return (segments);
}