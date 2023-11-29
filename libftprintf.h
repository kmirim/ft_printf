/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 05:46:51 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/11/29 06:06:55 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
char	*ft_putnbr_base(long long n, int base, char *digits);
int		ft_printf(const char *format, ...);
int		ft_putnbr_u(unsigned int n);
int		ft_puthex(unsigned long long n, const char fmt);
int		ft_printf_pointer(unsigned long long n);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
