/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:14:30 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/19 12:27:22 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "ft_printf/libftprintf.h"
# include "libft/libft.h"

extern char	**environ;

int		ft_isspace(char c);
void	ft_free_split(char **s1, char **s2);
void	ft_free(char *s1, char *s2);
void	fail_assign(char **s1, int idx);
char	handle_escape(char c);
char	*get_cmd_line(char *cmd);
char	**cmd_split(char *cmd);
char	**path_split(void);

pid_t	fork_dup(int pipe[2], char **argv, char *cmd, int idx);

#endif
