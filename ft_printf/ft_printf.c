/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:01:46 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/23 17:30:11 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_handle_specifier(va_list *ap, const char **format, int *printed)
{
	if (**format == 'c')
		*printed += ft_print_c(ap, format);
	else if (**format == 's')
		*printed += ft_print_s(ap, format);
	else if (**format == 'p')
		*printed += ft_print_ptr(ap, format);
	else if (**format == 'd' || **format == 'i')
		*printed += ft_print_d(ap, format);
	else if (**format == 'u')
		*printed += ft_print_u(ap, format);
	else if (**format == 'x' || **format == 'X')
		*printed += ft_print_hex(ap, format);
	else if (**format == '%')
	{
		*printed += write(1, *format, 1);
		(*format)++;
	}
	else
	{
		*printed = -1;
		return ;
	}
}

int	ft_printf(const char *format, ...)
{
	int		printed;
	va_list	ap;

	va_start(ap, format);
	printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_handle_specifier(&ap, &format, &printed);
			if (printed == -1)
			{
				write(1, "\ninvalid format!", 16);
				return (-1);
			}
		}
		else
		{
			printed += write(1, format, 1);
			format++;
		}
	}
	va_end(ap);
	return (printed);
}
