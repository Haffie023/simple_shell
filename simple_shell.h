#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

int _putchar(char c);
int main (void);
int prompt(void);
char **tokenize(char **buf);
int runscmd(char **tokens);
/**
* fork()
* execve
*/

#endif
