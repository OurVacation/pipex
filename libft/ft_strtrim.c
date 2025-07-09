/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:46:49 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/12 15:53:50 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	char	*nstr;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1) - 1;
	i = 0;
	while (ft_strchr(set, s1[i]) != 0 && s1[i] != 0)
		i++;
	while (ft_strchr(set, s1[s1_len]) != 0 && s1_len >= i)
		s1_len--;
	nstr = malloc(s1_len - i + 2);
	if (nstr == NULL)
		return (NULL);
	j = 0;
	while (i < s1_len + 1)
		nstr[j++] = s1[i++];
	nstr[j] = '\0';
	return (nstr);
}
