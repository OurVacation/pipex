/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:25:58 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/19 12:33:31 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	dup2_stdin_out(int redirect_to_stdin, int redirect_to_stdout)
{
	if (dup2(redirect_to_stdin, STDIN_FILENO) == -1)
	{
		perror("dup2 failed. when redirect to STDIN");
		exit(EXIT_FAILURE);
	}
	if (dup2(redirect_to_stdout, STDOUT_FILENO) == -1)
	{
		perror("dup2 failed. when redirect to STDOUT");
		exit(EXIT_FAILURE);
	}
}

void	ft_close_parent(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->pipe_num)
	{
		close(p->pipefd[i][0]);
		close(p->pipefd[i][1]);
		i++;
	}
	if (p->in_here_doc == 1 && p->here_doc_pipe[0] != -1)
	{
		close(p->here_doc_pipe[0]);
		close(p->here_doc_pipe[1]);
	}
}

void	ft_close_child(t_data *p, int read_fd, int write_fd)
{
	int	i;

	i = 0;
	while (i < p->pipe_num)
	{
		if (p->pipefd[i][0] != read_fd)
			close(p->pipefd[i][0]);
		if (p->pipefd[i][1] != write_fd)
			close(p->pipefd[i][1]);
		i++;
	}
}

int	ft_isspace(char c)
{
	return ((c == ' ' || (c >= 9 && c <= 13)));
}

char	handle_escape(char c)
{
	if (c == 'n')
		return ('\n');
	else if (c == 't')
		return ('\t');
	else if (c == 'r')
		return ('\r');
	else if (c == 'v')
		return ('\v');
	else if (c == 'f')
		return ('\f');
	else if (c == '\"')
		return ('\"');
	else if (c == ' ')
		return (' ');
	else if (c == '\\')
		return ('\\');
	else if (c == '\'')
		return ('\'');
	else
		return (c);
}
