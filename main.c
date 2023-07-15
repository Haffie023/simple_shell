#include "simple_shell.h"
#include <stdio.h>

/**
 * main - entry point
 *
 * Return: 0 on success
 */

int main(void)
{
	char *buf = NULL;
	char **segments = NULL;
	int i;

	while (1)
	{
		prompt();
		buf = getcmd();
		printf("%s", buf);
		segments = tokenize(&buf);
	}
	return (0);
}
