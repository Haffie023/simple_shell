#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>


int _putchar(char c);
int m
//ain (void);
int prompt(void);
char **tokenize(char **buf);
int runscmd(char **tokens);
/**
* fork()
* execve
*/

#endif
