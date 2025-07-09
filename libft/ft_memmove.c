/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:44:33 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/17 11:22:51 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cp;
	unsigned char	*src_cp;

	if (n == 0 || dest == src)
		return (dest);
	dest_cp = (unsigned char *)dest;
	src_cp = (unsigned char *)src;
	if (dest < src)
	{
		while (n--)
			*dest_cp++ = *src_cp++;
	}
	else
	{
		dest_cp += n;
		src_cp += n;
		while (n--)
			*--dest_cp = *--src_cp;
	}
	return (dest);
}
