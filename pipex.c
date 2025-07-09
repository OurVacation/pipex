/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:14:26 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/19 12:27:07 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		fd[2];
	int		pid[2];

	if (argc < 5)
		return (0);
	if (pipe(fd) == -1)
	{
		perror("pipe() failed");
		return (-1);
	}
	pid[0] = fork_dup(fd, argv, argv[2], 1);
	pid[1] = fork_dup(fd, argv, argv[3], 0);
	close(fd[0]);
	close(fd[1]);
	if (pid[0] == -1 || pid[1] == -1)
	{
		perror("fork failed");
		return (-1);
	}
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}
