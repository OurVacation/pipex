/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:21:34 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/12 15:46:07 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	to_find_len;

	if (*to_find == '\0')
		return ((char *)str);
	to_find_len = ft_strlen(to_find);
	if (to_find_len > len)
		return (NULL);
	i = 0;
	while (i + to_find_len <= len && str[i])
	{
		if (ft_memcmp(str + i, to_find, to_find_len) == 0)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
