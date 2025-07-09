/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:43:06 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/12 15:39:27 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_cp;
	const unsigned char	*src_cp;

	dest_cp = (unsigned char *)dest;
	src_cp = (unsigned char *)src;
	while (n--)
	{
		*dest_cp++ = *src_cp++;
	}
	return (dest);
}
