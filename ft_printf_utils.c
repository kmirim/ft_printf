/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:29:42 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/11/26 17:38:01 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	else
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free (str);
	return (len);
}

int	ft_numlen(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n && count++)
		n = n / base;
	return (count);
}

char	*ft_putnbr_base(int n, int base, char *digits)
{
	int		len;
	char	*arr;

	len = ft_numlen(n, base);
	if (n == 0)
		arr[len] = '0';
	if (n < 0)
		arr[0] = '0';
	while (n)
	{
		if (n > 0)
			arr[--len] = digits[n % base];
		else
			arr[--len] = digits [n % base * -1];
		n /= base;
	}
	return (ft_strdup(arr));
}
/*
char	*ft_putnbru(unsigned int)
{
	int             len;
        char    *arr;

        len = ft_numlen(n, base);
        if (n == 0)
                arr[len] = '0';
        if (n < 0)
                arr[0] = '0';
        while (n)
        	arr[--len] = digits[n % base];
	n /= base;
	return (arr);
}
*/
