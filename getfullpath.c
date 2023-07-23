#include "simple_shell.h"

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

	if (stat(segments[0], &statbuf) == 0)
	{
		return (strdup(segments[0]));
	}
	path = strdup(_getenv("PATH"));
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
/**
 * _getenv - impliments the getenv function
 * @str: variable to find (PATH)
 *
 * Return: pointer to contents of variable
 */

char *_getenv(char *str)
{
	char **temp;
	char *s;

	temp = environ;
	while (*temp)
	{
		s = strstr(*temp, str);
		if (s != NULL)
			break;
		temp = temp + 1;
	}
	return (&s[5]);
}
