#include "simple_shell.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

/**
 * getfullpath - is a which linux command implementation
 * gets the absolute path for a shortened command
 * @segments: an array of pointers to command and args
 * Return: pointer to fullpath if exists or NULL
 */

char *getfullpath(char **segments)
{
	char *path = NULL;
	char *token = NULL;
	char *fullpath = NULL;
	int cmd_len;
	struct stat statbuf;

	builtin(segments);
	path = strdup(getenv("PATH"));
	cmd_len = _strlen(segments[0]);
	token = strtok(path, ":");
	while (token != NULL)
	{
		fullpath = malloc(sizeof(char) * ((_strlen(token)) + cmd_len + 2));
		if (fullpath == NULL)
		{
			free(path);
			return (NULL);
		}
		strcpy(fullpath, token);
		strcat(fullpath, "/");
		strcat(fullpath, segments[0]);
		if (stat(fullpath, &statbuf) == 0)
		{
			free(path);
			return (fullpath);
		}
		token = strtok(NULL, ":");
		free(fullpath);
	}
	free(path);
	return (NULL);
}
