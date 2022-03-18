#include "minishell.h"

int execute(char *command, char **arg, char **env)
{
	if (ft_strncmp("echo", command, 4) == 0)
		echo(arg, env);
	else if (ft_strncmp("cd", command, 2) == 0)
		cd(arg, env);
	else if (ft_strncmp("pwd", command, 3) == 0)
		pwd(env);
	else if (ft_strncmp("export", command, 6) == 0)
		export(env);
	else if (ft_strncmp("unset", command, 5) == 0)
		unset();
	else if (ft_strncmp("env", command, 3) == 0)
		env(env);
	else if (ft_strncmp("exit", command, 4) == 0)
		exit();
	else
	{
		char * filepath = ft_strjoin("/bin/", arg[0]);
        execve(filepath, arg, env);
		// 이 밑이 어떻게 실행되는걸까....!!
        free(filepath);
	}
}

// -n
void echo(char *argv[], char **env)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{

	}
}

// arg : dir
void cd(char *argv[], char **env)
{
	int i;
	char **s;
	char dir[512];

	// 디렉토리 변경 -> 부모프로세스에서 변경적용이 안될듯
	// 				 환경변수 **env는 변경가능.
	chdir(argv[0]);
	getcwd(dir, 512);
	// 환경변수에 저장 어떻게?
	i = -1;
	while(!argv[++i])
	{
		s = ft_split(argv[i], '=');
		if (strncmp(s[0], "PWD", 3) == 0)
		{
			free(argv[i]);
			argv[i] = ft_strjoin(s[0], ft_strdup(dir));
		}
		free(s[0]);
		free(s[1]);
		free(s);
	}

}

void pwd()
{
	printf("%s", getenv("HOME"));
}


void export(char **env)
{

}

void unset(char **env)
{

}

void env(char **env)
{
	t_list *env_list;

	env_list = parse_envv(env);
	displayDoublyList(env_list);
}

void exit(char **env)
{

}