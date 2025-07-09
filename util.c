/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:25:58 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/19 12:33:58 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_isspace(char c)
{
	return ((c == ' ' || (c >= 9 && c <= 13)));
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
