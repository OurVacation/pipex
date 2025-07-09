/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:27:40 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/17 11:09:50 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	s_len;
	unsigned int	substr_len;
	unsigned int	i;

	s_len = (unsigned int)ft_strlen(s);
	if (s_len <= start)
		return (ft_calloc(1, 1));
	if ((s_len - start) >= (unsigned int)len)
		substr_len = (unsigned int)len;
	else
		substr_len = s_len - start;
	substr = malloc(substr_len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start] != 0 && substr_len > i)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
