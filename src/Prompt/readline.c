#include "../../Inc/minishell.h"

void parse_line(char *line, char **envv)
{
    static const char tok[] = " \t\n";
    char *arg[100]; // MAXARG 명시필요.
    char *str;
    char *save;
    int argv;
    int pid;

    argv = 0;
    str = strtok_r(line, tok, &save);
    while (str != NULL)
    {
        arg[argv++] = str;
        str = strtok_r(NULL, tok, &save);
    }
    arg[argv] = (char *)0;

    for(int i=0;i<argv;i++){
        printf("[%d]%s\n", i, arg[i]);
    }

    if (strcmp(arg[0], "quit") == 0) exit(1); // libft로 대체할것
    if ((pid = fork()) == -1) printf("FORK ERROR\n");
    else if (pid != 0){
        pid = wait(NULL);
    }
    else{
		execute(arg[0], arg, envv);
    }
}

void read_line(t_list *env_list, char *line, char **envv)
{

    char *info = ft_colorstr(get_node(env_list, get_position(env_list, "PWD"))->data);
    line = readline(info);
    free(info);
    if (line == NULL)
        exit(0);

    //printf("%s\n", line);
    parse_line(line, envv);

    add_history(line);
    free(line);
    line = NULL;
}
