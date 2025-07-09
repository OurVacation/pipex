# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 09:29:00 by taewonki          #+#    #+#              #
#    Updated: 2025/07/03 13:16:52 by taewonki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = pipex.c check.c cmd_parse.c env_parse.c processor.c util.c

BONUS_SRCS = cmd_parse_bonus.c env_parse_bonus.c free_exit_bonus.c \
			pipex_bonus.c processor_bonus.c util_bonus.c check_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT_A = libft/libft.a
PRINTF_A = ft_printf/libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

bonus : $(BONUS_OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_A) :
	$(MAKE) -C libft

$(PRINTF_A) :
	$(MAKE) -C ft_printf

clean :
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
