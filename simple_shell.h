#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

int _putchar(char c);
int main (void);
int prompt(void);
char *getcmd(void);
char **tokenize(char **buf);
/**
* parse - strtok, malloc, realloc
* fork()
* execve
*/

#endif
