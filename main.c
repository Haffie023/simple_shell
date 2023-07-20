#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - entry point
 *
 * Return: 0 on success
 */

int main(void)
{
	char *buf = NULL;
	char **segments = NULL;
	char *fullpath = NULL;
	size_t n = 0;
	int imode = 1;

	while (1 && imode)
	{
		if (!isatty(STDIN_FILENO))
			imode = 0;
		prompt();
		getline(&buf, &n, stdin);
		if (strncmp(buf, "\n", 1) == 0)
		{
			free(buf);
			continue;
		}
		segments = tokenize(buf);
		fullpath = getfullpath(segments);
		if (fullpath == NULL)
			fullpath = segments[0];
		runlcmd(fullpath, segments);
	}
	dfree(segments);
	free(buf);
	free(fullpath);
	return (0);
}
