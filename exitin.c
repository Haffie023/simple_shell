#include "simple_shell.h"
#include <stdlib.h>

/**
 * exitin - calls the exit function
 * @segments: array of pointers
 *
 * Return: 0 on success
 */

int  exitin(char **segments)
{
	dfree(segments);
	exit(0);
}