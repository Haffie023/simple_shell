#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - entry point
 *
 * Return: 0 on success
 */


//why is main having the void apa ivii ? Bacuse this is the engine of the whole code.
//Heelo uko apo bado
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
