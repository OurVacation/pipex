/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:43:36 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/19 12:46:09 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	redirect_fd(t_data *p, char **argv);
static void	redirect_here_doc(t_data *p, char **argv);
static void	get_user_input(t_data *p, char **argv);
void		set_info(t_data *p, int pipe_cnt, int here_doc, int argc);

void	fork_execve(t_data *p, char **argv)
{
	char	*cmd_line;
	char	**cmdv;

	p->pid[p->chd_n] = fork();
	if (p->pid[p->chd_n] < 0)
	{
		perror("fork() fail");
		clean_exit(p, 1);
	}
	if (p->pid[p->chd_n] == 0)
	{
		if (p->in_here_doc)
			redirect_here_doc(p, argv);
		else
			redirect_fd(p, argv);
		cmd_line = get_cmd_line(argv[p->in_here_doc + p->chd_n + 2]);
		cmdv = cmd_split(argv[p->in_here_doc + p->chd_n + 2]);
		if (execve(cmd_line, cmdv, environ) == -1)
		{
			free(cmd_line);
			ft_free_split(cmdv, NULL);
			exit(EXIT_FAILURE);
		}
		exit(0);
	}
}

void	set_info(t_data *p, int pipe_cnt, int here_doc, int argc)
{
	p->pipe_num = 0;
	p->chd_mx = pipe_cnt + 1;
	p->in_here_doc = here_doc;
	p->last_idx = argc - 1;
	p->pipefd = malloc (sizeof(int *) * pipe_cnt);
	while (p->pipe_num < pipe_cnt)
	{
		p->pipefd[p->pipe_num] = malloc(sizeof(int) * 2);
		if (p->pipefd[p->pipe_num] == NULL)
		{
			free_pipefd(p->pipefd, p->pipe_num);
			exit(EXIT_FAILURE);
		}
		if (pipe(p->pipefd[p->pipe_num]) == -1)
		{
			perror("pipe failed");
			free_pipefd(p->pipefd, p->pipe_num);
			exit(EXIT_FAILURE);
		}
		p->pipe_num++;
	}
}

static void	redirect_fd(t_data *p, char **argv)
{
	int	file_fd;

	if (p->chd_n == 0)
	{
		file_fd = open(argv[1], O_RDONLY);
		if (file_fd == -1)
			clean_exit(p, 1);
		dup2_stdin_out(file_fd, p->pipefd[0][1]);
		close(file_fd);
		ft_close_child(p, -1, p->pipefd[0][1]);
	}
	else if (p->chd_n > 0 && p->chd_n < p->chd_mx - 1)
	{
		dup2_stdin_out(p->pipefd[p->chd_n - 1][0], p->pipefd[p->chd_n][1]);
		ft_close_child(p, p->pipefd[p->chd_n - 1][0], p->pipefd[p->chd_n][1]);
	}
	else if (p->chd_n == p->chd_mx - 1)
	{
		file_fd = open(argv[p->last_idx], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (file_fd == -1)
			clean_exit(p, 1);
		dup2_stdin_out(p->pipefd[p->chd_n - 1][0], file_fd);
		close(file_fd);
		ft_close_child(p, p->pipefd[p->chd_n - 1][0], -1);
	}
}

static void	redirect_here_doc(t_data *p, char **argv)
{
	int	file_fd;

	if (p->chd_n == 0)
	{
		get_user_input(p, argv);
		dup2_stdin_out(p->here_doc_pipe[0], p->pipefd[0][1]);
		close(p->here_doc_pipe[0]);
		ft_close_child(p, -1, p->pipefd[0][1]);
	}
	else if (p->chd_n > 0 && p->chd_n < p->chd_mx - 1)
	{
		dup2_stdin_out(p->pipefd[p->chd_n - 1][0], p->pipefd[p->chd_n][1]);
		ft_close_child(p, p->pipefd[p->chd_n - 1][0], p->pipefd[p->chd_n][1]);
	}
	else if (p->chd_n == p->chd_mx - 1)
	{
		file_fd = open(argv[p->last_idx], O_CREAT | O_APPEND | O_WRONLY, 0644);
		if (file_fd == -1)
			clean_exit(p, 1);
		dup2_stdin_out(p->pipefd[p->chd_n - 1][0], file_fd);
		close(file_fd);
		ft_close_child(p, p->pipefd[p->chd_n - 1][0], -1);
	}
}

static void	get_user_input(t_data *p, char **argv)
{
	char	buf[1024];
	char	*lim;
	int		l_len;
	int		n;

	lim = argv[2];
	if (pipe(p->here_doc_pipe) == -1)
	{
		perror("here_doc_pipe fail");
		exit(EXIT_FAILURE);
	}
	l_len = ft_strlen(lim);
	while (1)
	{
		ft_printf("heredoc> ");
		n = read(STDIN_FILENO, buf, 1023);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		if (ft_strncmp(buf, lim, ft_strlen(lim)) == 0 && buf[l_len] == '\n')
			break ;
		ft_putstr_fd(buf, p->here_doc_pipe[1]);
	}
	close(p->here_doc_pipe[1]);
}
