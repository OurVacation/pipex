/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:36:47 by taewonki          #+#    #+#             */
/*   Updated: 2025/05/13 10:38:52 by taewonki         ###   ########.fr       */
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

static char	*itoa_base(unsigned int num, const char *hex)
{
	int				size;
	char			*result;
	unsigned int	n;

	n = num;
	size = 0;
	while (n)
	{
		n /= 16;
		size++;
	}
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	result[size] = '\0';
	while (size--)
	{
		result[size] = hex[num % 16];
		num /= 16;
	}
	return (result);
}

int	ft_print_hex(va_list *ap, const char **format)
{
	int				result;
	char			*print;
	unsigned int	num;

	result = 0;
	num = va_arg(*ap, unsigned int);
	if (num == 0)
	{
		(*format)++;
		return (write(1, "0", 1));
	}
	if (**format == 'x')
		print = itoa_base(num, "0123456789abcdef");
	else if (**format == 'X')
		print = itoa_base(num, "0123456789ABCDEF");
	else
		return (0);
	(*format)++;
	if (!print)
		return (0);
	result += write(1, print, ft_strlen(print));
	free(print);
	return (result);
}
