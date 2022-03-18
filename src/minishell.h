/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:21:43 by gshim             #+#    #+#             */
/*   Updated: 2022/03/18 22:16:47 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../include/libft/libft.h"
/* readline함수를 사용하기위한 헤더 */
# include <readline/readline.h>
/* add_history함수를 사용하기위한 헤더 */
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int execute(char *command, char **arg, char **env);
void echo(char *argv[], char **env);
void cd(char *argv[], char **env);
void pwd();
void export(char **env);
void unset(char **env);
void env(char **env);
void exit(char **env);

#endif