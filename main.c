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

	prompt();
	buf = getcmd();
	printf("%s", buf);
	return (0);
}
