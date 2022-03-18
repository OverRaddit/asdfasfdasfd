#include "minishell.h"

void echo(char *argv[], bool n)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{

	}
}

void pwd()
{
	printf("%s", getenv("HOME"));
}

void cd(const char *dir)
{
	chdir(dir);
}

void export(const char *key, const char *value)
{

}