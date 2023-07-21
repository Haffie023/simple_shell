#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#define BUFFER 10
int _putchar(char c);
int main (int ac __attribute__((unused)), char **av __attribute__((unused)), char **env);
int prompt(void);
int _strlen(char *s);
char **tokenize(char *buf);
void dfree(char **arr);
void sfree(char *arr);
int runlcmd(char *cmd, char **tokens, char **envt);
char *getfullpath(char **segments);
int no_delim(char *str);
#endif
