/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:54:03 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/11/29 05:44:54 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_uns_numlen(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= 10;
	return (count);
}

static char	*ft_utoa(unsigned int n)
{
	int			len;
	char		*ret;
	const char	*digits = "0123456789";

	len = ft_uns_numlen(n);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = 0;
	if (n == 0)
		ret[0] = '0';
	while (n)
	{
		if (n > 0)
		{
			ret[--len] = digits[n % 10];
			n /= 10;
		}
	}
	return (ret);
}

int	ft_putnbr_u(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_utoa(n);
	len = ft_putstr(str);
	free (str);
	return (len);
}
