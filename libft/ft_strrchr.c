/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:53:35 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/12 15:46:36 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char		*last;
	unsigned char	search;

	last = NULL;
	search = (unsigned char)c;
	while (*str)
	{
		if (*str == search)
			last = str;
		str++;
	}
	if (search == '\0')
		return ((char *)str);
	return ((char *)last);
}
