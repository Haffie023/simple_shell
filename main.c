#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - entry point
 * @ac: count of command and args
 * @av: array of pointers to command and args
 * @env: environment variables
 * Return: 0 on success
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	char *buf = NULL;
	char **segments = NULL;
	char *fullpath = NULL;
	size_t n = 0;
	int imode = 1;
	int flag = 1;

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
		{
			fullpath = segments[0];
			flag = 0;
		}
		runlcmd(fullpath, segments, env);
		dfree(segments);
		if (flag)
			sfree(fullpath);
	}
	free(buf);
	return (0);
}
