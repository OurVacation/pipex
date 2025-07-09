/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:58:35 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/24 12:59:38 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static size_t	word_num(char *cmd)
{
	int		in_quote;
	int		in_word;
	size_t	count;

	in_quote = 0;
	in_word = 0;
	count = 0;
	while (*cmd)
	{
		if (*cmd == '\'')
			in_quote ^= 1;
		if (*cmd != ' ' || in_quote)
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
			in_word = 0;
		cmd++;
	}
	return (count);
}

static size_t	get_len(char *cmd)
{
	size_t	len;

	len = 0;
	if (*cmd == '\'')
	{
		cmd++;
		while (cmd[len] && (cmd[len] != '\''
				|| (len > 0 && cmd[len - 1] == '\\' )))
			len++;
		return (len + 2);
	}
	else
	{
		while (cmd[len] && cmd[len] != ' ')
			len++;
		return (len);
	}
}

static size_t	ft_cmd_copy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dest || !src)
		return (0);
	i = 0;
	j = 0;
	if (src[i] == '\'')
		i++;
	while (src[i] && j < size - 1)
	{
		if (src[i] == '\'')
			break ;
		else
			dest[j++] = src[i++];
	}
	dest[j] = '\0';
	return (j);
}

static int	assign_val(char **nstr_arr, char *cmd, size_t word)
{
	char	*start;
	size_t	len;
	size_t	i;

	start = cmd;
	i = 0;
	while (*start && i < word)
	{
		while (ft_isspace(*start))
			start++;
		len = get_len(start);
		nstr_arr[i] = malloc(len + 1);
		if (nstr_arr[i] == NULL)
		{
			fail_assign(nstr_arr, i);
			return (0);
		}
		ft_cmd_copy(nstr_arr[i], start, len + 1);
		start += len;
		i++;
	}
	nstr_arr[i] = NULL;
	return (1);
}

char	**cmd_split(char *cmd)
{
	char	*temp;
	char	**nstr_arr;
	size_t	token;

	if (!cmd)
		return (NULL);
	temp = cmd;
	token = word_num(cmd);
	nstr_arr = malloc(sizeof(char *) * (token + 1));
	if (!nstr_arr)
		return (NULL);
	if (!assign_val(nstr_arr, temp, token))
		return (NULL);
	return (nstr_arr);
}
