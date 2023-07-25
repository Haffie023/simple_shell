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
	int status = 0;

	if (segments[1] != NULL)
		status = atoi(segments[1]);	
	dfree(segments);
	exit(status);
}
