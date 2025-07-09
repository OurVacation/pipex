/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:23:09 by gimtaewon         #+#    #+#             */
/*   Updated: 2025/06/19 11:57:39 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

typedef struct s_data {
	int		**pipefd;
	int		pipe_num;
	int		here_doc_pipe[2];
	int		chd_mx;
	int		chd_n;
	int		in_here_doc;
	int		last_idx;
	pid_t	pid[1024];
}	t_data;

extern char	**environ;

char	**cmd_split(char *cmd);
char	**path_split(void);
char	*get_cmd_line(char *cmd);

void	free_pipefd(int **pipefd, int idx);
void	ft_free_split(char **s1, char **s2);
void	fail_assign(char **s1, int idx);
void	ft_free(char *s1, char *s2);
void	clean_exit(t_data *process, int exit_flag);
void	dup2_stdin_out(int redirect_to_stdin, int redirect_to_stdout);
void	ft_close_child(t_data *p, int read_fd, int write_fd);
void	ft_close_parent(t_data *p);

void	set_info(t_data *p, int pipe_cnt, int here_doc, int argc);
void	fork_execve(t_data *p, char **argv);

int		ft_isspace(char c);
void	ft_close(t_data *p, int file_fd);
char	handle_escape(char c);
#endif
