/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_uhex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:07:16 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/16 18:04:40 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../converters.h"

int	putuhexll(unsigned long long n, int upper, int fd)
{
	char	*set;
	int		res;

	if (upper)
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	res = 0;
	if (n > 15)
		res = putuhexll(n / 16, upper, fd);
	if (res == -1)
		return (-1);
	if (!write(fd, set + (n % 16), 1))
		return (-1);
	return (res + 1);
}

static unsigned long long	getarg(va_list args, t_subspec subspec)
{
	if (subspec.lenmod == hh)
		return ((unsigned long long)(unsigned char) va_arg(args, int));
	if (subspec.lenmod == h)
		return ((unsigned long long)(unsigned short) va_arg(args, int));
	if (subspec.lenmod == l)
		return ((unsigned long long) va_arg(args, unsigned long));
	if (subspec.lenmod == ll)
		return (va_arg(args, unsigned long long));
	if (subspec.lenmod == j)
		return ((unsigned long long) va_arg(args, uintmax_t));
	if (subspec.lenmod == z)
		return ((unsigned long long) va_arg(args, size_t));
	if (subspec.lenmod == t)
		return ((unsigned long long) va_arg(args, t_ptrdiff_t));
	return ((unsigned long long) va_arg(args, unsigned int));
}

int	c_uhex(va_list args, t_subspec subspec, int upper, int fd)
{
	unsigned long long	n;
	int					len;

	n = getarg(args, subspec);
	len = 0;
	if (subspec.force_sign)
		len = write(fd, "+", 1);
	if (len == -1)
		return (-1);
	return (len + putuhexll(n, upper, fd));
}
