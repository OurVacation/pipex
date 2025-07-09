/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:45:00 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/22 18:51:40 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != 0)
		count++;
	return (count);
}

int	ft_print_s(va_list *ap, const char **format)
{
	char	*object;

	(*format)++;
	object = va_arg(*ap, char *);
	if (!object)
	{
		return (write(1, "(null)", 6));
	}
	return (write(1, object, ft_strlen(object)));
}
