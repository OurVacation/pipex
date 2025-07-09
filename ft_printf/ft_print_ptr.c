/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:29:31 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/22 19:05:43 by taewonki         ###   ########.fr       */
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

static char	*itoa_base(unsigned long num, const char *hex)
{
	int				size;
	char			*result;
	unsigned long	n;

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

int	ft_print_ptr(va_list *ap, const char **format)
{
	int				result;
	char			*print;
	void			*ptr;
	unsigned long	addr;

	ptr = va_arg(*ap, void *);
	addr = (unsigned long)ptr;
	if (!ptr || addr == 0)
	{
		(*format)++;
		return (write(1, "(nil)", 5));
	}
	result = write (1, "0x", 2);
	print = itoa_base(addr, "0123456789abcdef");
	if (!print)
		return (0);
	result += write(1, print, ft_strlen(print));
	(*format)++;
	free(print);
	return (result);
}
