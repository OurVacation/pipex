/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:54:25 by taewonki          #+#    #+#             */
/*   Updated: 2025/05/14 16:11:23 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putnbr_u(unsigned int n)
{
	int		result;
	char	mod;

	result = 0;
	if (n >= 10)
		result += ft_putnbr_u(n / 10);
	mod = n % 10 + '0';
	result += write(1, &mod, 1);
	return (result);
}

int	ft_print_u(va_list *ap, const char **format)
{
	unsigned int	uint;

	uint = va_arg(*ap, unsigned int);
	(*format)++;
	return (ft_putnbr_u(uint));
}
