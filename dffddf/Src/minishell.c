#include "../Inc/minishell.h"


// void print_info()
// {
//     char dir[100];

//     getcwd(dir, 100);
//     printf ("%s >",dir);
// }

// void sigHandler(int sig)
// {
//         if (sig == SIGINT)
//             exit(0);
// }


// int main(int argc, char **argv, char **envv)
// {
//     (void)argv;
//     if (argc == 1)
//     {
//         init_envv(envv);
//         while (1)
//         {
//             print_info();
//             signal(SIGINT, sigHandler);
//         }
//     }
//     ft_error(1);
//     return (0);
// }


#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signum)
{
    if (signum != SIGINT)
        return;

    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
    printf("ctrl + c pressed\n");	// for DEBUG
    printf("\n");
}

int main(void)
{
    int ret;
    char *line;

    signal(SIGINT, handler);
    while (1)
    {
        line = readline("users/kyujlee> ");
		printf("READLINE COMPLETE\n");
        if (line)
        {
            if (ret)
                printf("output> %s\n", line);
            add_history(line);
            free(line);
            line = NULL;
        }
        else
        {
            printf("ctrl + d\n");
        }
    }
    return (0);
}
// gcc minishell.c -lreadline -L/Users/gshim/.brew/opt/readline/lib -I/Users/gshim/.brew/opt/readline/include


/*
ctrl c 연속시 정상작똥
다른 입력 후 ctrl c 시 첫번째 동작x
aa -> ctrl c

printf -> redisplay => printf가 프롬프트를 덮어쓰고있음
redisplay -> printf => 프롬프트 뒤에 printf가 나옴
*/