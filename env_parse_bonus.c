/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:56:38 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/18 14:12:41 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(void)
{
	char	**env;
	char	*path;

	env = environ;
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			path = ft_strdup(*env + 5);
			if (!path)
				return (NULL);
			return (path);
		}
		env++;
	}
	return (NULL);
}

char	**path_split(void)
{
	char	*path;
	char	*temp;
	char	**result;
	char	**splited_path;

	path = get_path();
	if (path == NULL)
		return (NULL);
	splited_path = ft_split(path, ':');
	free(path);
	if (splited_path == NULL)
		return (NULL);
	result = splited_path;
	while (*splited_path)
	{
		temp = *splited_path;
		*splited_path = ft_strjoin(*splited_path, "/");
		if (!*splited_path)
			ft_free_split(result, NULL);
		if (!*splited_path)
			return (NULL);
		free(temp);
		splited_path++;
	}
	return (result);
}
// 환경변수 다 쪼개서 스트링 배열로 만들고
// 각 요소 뒤에 명령어만 바로 붙이면 되도록 / 추가해서 return
