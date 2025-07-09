/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:27:35 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/11 10:55:16 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	search;

	search = (unsigned char)c;
	while (*str != 0)
	{
		if (*str == search)
			return ((char *)str);
		str++;
	}
	if (search == '\0')
		return ((char *)str);
	return (NULL);
}
