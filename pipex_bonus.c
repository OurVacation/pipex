/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:22:01 by gimtaewon         #+#    #+#             */
/*   Updated: 2025/06/19 12:26:45 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	wait_all_children(t_data *parent);

int	main(int argc, char **argv)
{
	static t_data	parent;

	if (argc < 5)
		return (-1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
		set_info(&parent, argc - 5, 1, argc);
	else
		set_info(&parent, argc - 4, 0, argc);
	if (parent.pipefd == NULL)
		return (-1);
	parent.chd_n = 0;
	while (parent.chd_n < parent.chd_mx)
	{
		fork_execve(&parent, argv);
		if (parent.pid[parent.chd_n] < 0)
			clean_exit(&parent, 1);
		parent.chd_n++;
	}
	ft_close_parent(&parent);
	wait_all_children(&parent);
	clean_exit(&parent, 0);
	return (0);
}

static void	wait_all_children(t_data *parent)
{
	int	i;

	i = 0;
	while (i < parent->chd_mx)
	{
		if (parent->pid[i] > 0)
			waitpid(parent->pid[i], NULL, 0);
		i++;
	}
}
