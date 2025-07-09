/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:58:09 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/19 13:01:14 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	dup_handle(int pipe[2], char **argv, int idx)
{
	int	fd;

	if (idx == 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("open() failed");
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		dup2(pipe[1], STDOUT_FILENO);
	}
	if (idx == 0)
	{
		fd = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (fd == -1)
			exit(EXIT_FAILURE);
		dup2(pipe[0], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
	}
	close(pipe[0]);
	close(pipe[1]);
	close(fd);
}

pid_t	fork_dup(int pipe[2], char **argv, char *cmd, int idx)
{
	pid_t	pid;
	char	*cmd_line;
	char	**cmdv;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		cmd_line = get_cmd_line(cmd);
		cmdv = cmd_split(cmd);
		if (!cmd_line || !cmdv)
			return (-1);
		dup_handle(pipe, argv, idx);
		if (execve(cmd_line, cmdv, environ) == -1)
		{
			free(cmd_line);
			ft_free_split(cmdv, NULL);
			exit(EXIT_FAILURE);
		}
		exit(0);
	}
	return (pid);
}
