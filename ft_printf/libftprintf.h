/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:38:43 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/23 17:24:33 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_c(va_list *ap, const char **format);
int	ft_print_d(va_list *ap, const char **format);
int	ft_print_s(va_list *ap, const char **format);
int	ft_print_hex(va_list *ap, const char **format);
int	ft_print_ptr(va_list *ap, const char **format);
int	ft_print_u(va_list *ap, const char **format);

#endif
