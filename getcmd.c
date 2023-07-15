#include "simple_shell.h"
#include <stdio.h>

/**
 * getcmd - reads an entire line from stdin using getline fuction
 *
 * Return: Address of buffer containing the text
 */

char *getcmd(void)
{
	char *buf = NULL;
	size_t n = 0;

	getline(&buf, &n, stdin);
	return (buf);
}
