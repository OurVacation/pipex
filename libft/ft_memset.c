/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:39:45 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/09 16:15:23 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*result;
	unsigned char	element;

	result = (unsigned char *)s;
	element = (unsigned char)c;
	i = 0;
	while (n > i)
	{
		result[i] = element;
		i++;
	}
	return ((void *)result);
}
