/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 03:55:57 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/11/29 06:15:04 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_format(const char *specifier, va_list *ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1)))
		{
			format++;
			ret = ret + ft_check_format(format, &ap);
		}
		else
			ret = ret + ft_putchar(*format);
		format++;
	}
	va_end (ap);
	return (ret);
}

int	ft_check_format(const char *specifier, va_list *ap)
{
	if (*specifier == '%')
		return (ft_putchar('%'));
	else if (*specifier == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (*specifier == 'd' || *specifier == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (*specifier == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (*specifier == 'u')
		return (ft_putnbr_u(va_arg(*ap, unsigned int)));
	else if (*specifier == 'x')
		return (ft_puthex(va_arg(*ap, unsigned int), 'x'));
	else if (*specifier == 'X')
			return (ft_puthex(va_arg(*ap, unsigned int), 'X'));
	else if (*specifier == 'p')
		return (ft_printf_pointer(va_arg(*ap, unsigned long long)));
	else
		return (0);
}
