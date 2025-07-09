/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimtaewon <gimtaewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:22:45 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/16 19:55:36 by gimtaewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	nstr_len;
	char	*nstr;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	nstr_len = ft_strlen(s1) + ft_strlen(s2);
	nstr = malloc(nstr_len + 1);
	if (nstr == NULL)
		return (NULL);
	result = nstr;
	while (*s1)
		*nstr++ = *s1++;
	while (*s2)
		*nstr++ = *s2++;
	*nstr = '\0';
	return (result);
}
