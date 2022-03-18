# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gshim <gshim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 17:48:50 by gshim             #+#    #+#              #
#    Updated: 2022/03/18 22:15:32 by gshim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = minishell

SRCS_DIR = ./src
SRCS =  src/DataStructure/linkedlist1.c src/DataStructure/linkedlist2.c \
	src/Parsing/parse_envv.c \
	src/Prompt/readline.c src/Prompt/sighandle.c \
	src/Utilities/utils1.c src/Utilities/utils2.c \
	src/minishell.c src/builtIn.c
OBJS = $(SRCS:.c=.o)

#======================= 외부라이브러리 모음 ==========================
LIB_NAME = ft
LIB_DIR = ./include/libft
LIB = $(addprefix $(LIB_DIR)/, libft.a)

#=================================================================

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR) bonus
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) \
	-lreadline -L/Users/gshim/.brew/opt/readline/lib \
	-I/Users/gshim/.brew/opt/readline/include $^ -o $@

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean

fclean :
	rm -rf $(NAME) $(OBJS)
	$(MAKE) -C $(LIB_DIR) fclean

re : fclean all

.PHONY : all clean fclean re
