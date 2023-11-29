/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 02:12:33 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/11/29 05:29:54 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_count_num(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned long long n, const char fmt)
{
	if (n > 15)
	{
		ft_puthex(n / 16, fmt);
		ft_puthex(n % 16, fmt);
	}
	else
	{
		if (n >= 10)
		{
			if (fmt == 'x' || fmt == 'p')
				ft_putchar_fd(n - 10 + 'a', 1);
			else
				ft_putchar_fd(n - 10 + 'A', 1);
		}
		else
			ft_putchar_fd(n + 48, 1);
	}
	return (ft_count_num(n));
}
