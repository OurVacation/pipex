/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:10:22 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/22 12:08:11 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putnbr(int n)
{
	int		result;
	char	mod;

	result = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		n = -n;
		result += write(1, "-", 1);
	}
	if (n >= 10)
		result += ft_putnbr(n / 10);
	mod = n % 10 + '0';
	result += write(1, &mod, 1);
	return (result);
}

int	ft_print_d(va_list *ap, const char **format)
{
	int	num;

	num = va_arg(*ap, int);
	(*format)++;
	return (ft_putnbr(num));
}
