/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:29:02 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/22 18:52:31 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_c(va_list *ap, const char **format)
{
	char	object;

	object = va_arg(*ap, int);
	(*format)++;
	return (write(1, &object, 1));
}
