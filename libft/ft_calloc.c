/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:26:51 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/12 16:07:32 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	max;
	size_t	area;

	max = (size_t)-1;
	if (size != 0 && nmemb > max / size)
		return (NULL);
	area = nmemb * size;
	memory = malloc(area);
	if (memory != NULL)
		ft_memset(memory, 0, area);
	return (memory);
}
