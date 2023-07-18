#include "simple_shell.h"
#include <unistd.h>
#include <sys/wait.h>

/**
 * runscmd - executes full path commands e.g "/bin/ls"
 * @tokens: the command
 *
 * Return: 0 on success
 */

int runscmd(char **tokens)
{
	int i;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		return (-1);
	}
	if (pid == 0)
	{
		i = execve(tokens[0], tokens, NULL);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
