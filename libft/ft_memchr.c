/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:17:50 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/11 11:23:44 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char		search;
	const unsigned char	*s;

	s = (unsigned char *)str;
	search = (unsigned char)c;
	while (n--)
	{
		if (*s == search)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
