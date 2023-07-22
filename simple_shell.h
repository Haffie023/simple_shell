#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#define BUFFER 10

/**
 * struct shell_func - Handles the shell functions in our simple shell
 * @s: function
 * @f: function pointer
 *
 */
typedef struct shell_func
{
	char *s;
	void (*f)(char **seg);
} sf;
int _putchar(char c);
int main (int ac, char **av __attribute__((unused)), char **env);
int prompt(void);
int _strlen(char *s);
char **tokenize(char *buf);
void dfree(char **arr);
void sfree(char *arr);
int runlcmd(char *cmd, char **tokens, char **envt);
char *getfullpath(char **segments);
int no_delim(char *str);
int builtin(char **segments);
void exitin(char **segments);
#endif
