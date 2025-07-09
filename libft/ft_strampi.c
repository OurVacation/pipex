/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strampi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:34:16 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/12 15:52:31 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	unsigned int	len;
	char			*nstr;

	if (!s || !f)
		return (NULL);
	len = (unsigned int)ft_strlen(s);
	nstr = malloc(len + 1);
	if (nstr == NULL)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		nstr[idx] = f(idx, s[idx]);
		idx++;
	}
	nstr[idx] = '\0';
	return (nstr);
}
