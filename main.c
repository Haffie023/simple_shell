#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	char *path = getenv("PATH");
	size_t n = 0;
	ssize_t i;
	int flag;
	int imode = 1;

	while (1 && imode)
	{
		if (!isatty(STDIN_FILENO))
			imode = 0;
		prompt();
		i = getline(&buf, &n, stdin);
		segments = tokenize(&buf);
		printf("%s\n", path);
		fullpath = getfullpath(segments);
		if (fullpath == NULL)
			fullpath = segments[0];
		runlcmd(fullpath, segments);
	}
	free(segments);
	free(buf);
}
