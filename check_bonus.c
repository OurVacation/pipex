/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:25:37 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/18 15:28:41 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

#include "pipex.h"

char	*get_cmd_line(char *cmd)
{
	char	*check;
	char	**env_path;
	char	**cmd_line;
	int		i;

	env_path = path_split();
	cmd_line = cmd_split(cmd);
	if (!env_path || !cmd_line)
		return (NULL);
	i = 0;
	while (env_path[i])
	{
		check = ft_strjoin(env_path[i], cmd_line[0]);
		if (access(check, X_OK) == 0)
		{
			ft_free_split(env_path, cmd_line);
			return (check);
		}
		i++;
		free(check);
	}
	return (NULL);
}
