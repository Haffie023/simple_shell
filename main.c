#include "simple_shell.h"
#include <stdio.h>
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
	}
	return (0);
}
