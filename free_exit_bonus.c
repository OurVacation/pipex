/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:03:32 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/19 12:26:17 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_pipefd(int **pipefd, int idx)
{
	int	i;

	i = 0;
	if (!pipefd || !*pipefd)
		return ;
	while (i < idx)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
		free(pipefd[i]);
		i++;
	}
	free(pipefd);
}

void	clean_exit(t_data *p, int exit_flag)
{
	free_pipefd(p->pipefd, p->pipe_num);
	if (p->here_doc_pipe[0] != -1)
		close(p->here_doc_pipe[0]);
	if (p->here_doc_pipe[1] != -1)
		close(p->here_doc_pipe[1]);
	if (exit_flag == 1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
}

void	ft_free_split(char **s1, char **s2)
{
	int	i;

	if (s1)
	{
		i = -1;
		while (s1[++i])
			free(s1[i]);
		free(s1);
	}
	if (s2)
	{
		i = -1;
		while (s2[++i])
			free(s2[i]);
		free(s2);
	}
}

void	fail_assign(char **s1, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(s1[i]);
		i++;
	}
	free(s1);
}

void	ft_free(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}
