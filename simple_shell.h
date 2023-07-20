#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#define BUFFER 10
int _putchar(char c);
int main (void);
int prompt(void);
int _strlen(char *s);
char **tokenize(char *buf);
void dfree(char **arr);
int runlcmd(char *cmd, char **tokens);
char *getfullpath(char **segments);
int no_delim(char *str);
#endif
