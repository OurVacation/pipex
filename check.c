/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:17:23 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/03 13:16:58 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
