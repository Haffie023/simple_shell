#include "simple_shell.h"
#include <stdlib.h>

/**
 * exitin - calls the exit function
 * @segments: array of pointers
 *
 * Return: Nothing
 */

void exitin(char **segments )
{
	dfree(segments);
	exit(0);
}
