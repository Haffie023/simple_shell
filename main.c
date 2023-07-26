#include "simple_shell.h"

/**
 * main - entry point
 * @ac: count of command and args
 * @av: array of pointers to command and args
 * @env: environment variables
 * Return: 0 on success
 */

int main(int ac __attribute__((unused)), char **av, char **env)
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
		if (buf[0] == '\n')
		{
			continue;
		}
		segments = tokenize(buf);
		if (builtin(segments) == 0)
			continue;
		fullpath = getfullpath(segments);
		if (fullpath == NULL)
		{
			perror(av[0]);
			dfree(segments);
			continue;
		}
		runlcmd(fullpath, segments, env);
		dfree(segments);
		if (flag)
			sfree(fullpath);
	}
	free(buf);
	return (0);
}
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
	size_t n = 0;
	ssize_t i;
	int imode = 1;

	while (1 && imode)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt();
		}
		else
		{
			imode = 0;
		}
		i = getline(&buf, &n, stdin);
		segments = tokenize(&buf);
		runscmd(segments);
		free(segments);
		free(buf);
	}
	return (0);
}
