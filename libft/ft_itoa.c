/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:28:16 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/17 10:11:19 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev_arr(char	*arr, int size, int sign)
{
	int		min;
	int		max;
	char	temp;

	max = size - 1;
	if (sign == -1)
		min = 1;
	else
		min = 0;
	while (min <= max)
	{
		temp = arr[max];
		arr[max] = arr[min];
		arr[min] = temp;
		min++;
		max--;
	}
}

static char	*get_mem(long long num)
{
	char	*arr;
	size_t	len;

	len = 0;
	if (num == 0)
	{
		arr = malloc(2);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	arr = malloc(len + 1);
	return (arr);
}

char	*ft_itoa(int n)
{
	int			i;
	int			sign;
	char		*result;
	long long	num;

	num = (long long)n;
	result = get_mem(num);
	i = 0;
	sign = 1;
	if (num == 0)
		return (result);
	if (num < 0)
	{
		sign = -1;
		num = -num;
		result[i++] = '-';
	}
	while (num > 0)
	{
		result[i++] = (num % 10) + '0';
		num /= 10;
	}
	result[i] = '\0';
	ft_rev_arr(result, i, sign);
	return (result);
}
