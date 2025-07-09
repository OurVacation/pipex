/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:43:25 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/19 12:34:58 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_num(char *str, char c)
{
	size_t	i;
	size_t	word;
	int		in_word;

	i = 0;
	word = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != c && in_word == 0)
		{
			in_word = 1;
			word++;
		}
		else if (str[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (word);
}

static void	arr_free(char **nstr_arr, size_t i)
{
	while (i--)
		free(nstr_arr[i]);
	free(nstr_arr);
}

static size_t	get_len(char *ptr, char c)
{
	char	*end;

	end = ft_strchr(ptr, c);
	if (end)
		return (end - ptr);
	else
		return (ft_strlen(ptr));
}

static int	assign_val(char **nstr_arr, char *s, size_t word, char c)
{
	char	*start;
	size_t	len;
	size_t	i;

	start = s;
	i = 0;
	while (*start && i < word)
	{
		while (*start == c)
			start++;
		len = get_len(start, c);
		nstr_arr[i] = malloc(len + 1);
		if (nstr_arr[i] == NULL)
		{
			arr_free(nstr_arr, i);
			return (1);
		}
		ft_strlcpy(nstr_arr[i], start, len + 1);
		start += len;
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	*temp;
	char	**nstr_arr;
	size_t	word;

	if (s == NULL)
		return (NULL);
	temp = (char *)s;
	while (*temp && *temp == c)
		temp++;
	word = word_num(temp, c);
	nstr_arr = malloc((word + 1) * sizeof(char *));
	if (nstr_arr == NULL)
		return (NULL);
	if (assign_val(nstr_arr, temp, word, c))
		return (NULL);
	nstr_arr[word] = NULL;
	return (nstr_arr);
}
