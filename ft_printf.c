/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:19:36 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/11/26 17:37:35 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

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
		return (ft_putnbr(va_arg(*ap, unsigned int)));
	else if (*specifier == 'x' || *specifier == 'X')
	{
		if (*specifier == 'x')
			return (ft_putstr(ft_putnbr_base(va_arg(*ap, int), 16, "0123456789ABCDEF")));
		else
			return (ft_putstr(ft_putnbr_base(va_arg(*ap, int), 16, "0123456789abcdef")));
	}
	else if (*specifier == 'p')
		return (ft_putstr("0x"));
	else
		return (0);
}
/*
int main (void)
{
	ft_printf("banana%s", "aiaiaia");
	return (0);
}*/
