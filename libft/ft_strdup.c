/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:12:58 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/11 13:32:55 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	dup = malloc(ft_strlen(s) + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
