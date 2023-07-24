#include "simple_shell.h"
#include <unistd.h>
#include <sys/wait.h>

/**
 * runlcmd - executes full path commands e.g "/bin/ls"
 * @cmd: absolute path to command's program
 * @tokens: the command
 * @envt: environment variables
 * Return: 0 on success
 */

int runlcmd(char *cmd, char **tokens, char **envt)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		return (-1);
	}
	if (pid == 0)
	{
		execve(cmd, tokens, envt);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
