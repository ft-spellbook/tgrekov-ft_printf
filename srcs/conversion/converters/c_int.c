/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:18:23 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/16 18:06:24 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../converters.h"

static int	putll(long long n, int fd)
{
	char	c;
	int		res;

	res = 0;
	if (n > 9)
		res = putll(n / 10, fd);
	if (res == -1)
		return (-1);
	c = n % 10 + '0';
	if (!write(fd, &c, 1))
		return (-1);
	return (res + 1);
}

static long long	getarg(va_list args, t_subspec subspec)
{
	if (subspec.lenmod == hh)
		return ((long long)(signed char) va_arg(args, int));
	if (subspec.lenmod == h)
		return ((long long)(short) va_arg(args, int));
	if (subspec.lenmod == l)
		return ((long long) va_arg(args, long));
	if (subspec.lenmod == ll)
		return (va_arg(args, long long));
	if (subspec.lenmod == j)
		return ((long long) va_arg(args, intmax_t));
	if (subspec.lenmod == z)
		return ((long long) va_arg(args, size_t));
	if (subspec.lenmod == t)
		return ((long long) va_arg(args, t_ptrdiff_t));
	return ((long long) va_arg(args, int));
}

int	c_int(va_list args, t_subspec subspec, int fd)
{
	long long	n;
	int			len;

	n = getarg(args, subspec);
	if (n == (-LLONG_MAX - 1LL))
		return (write(fd, "-9223372036854775808", 20));
	len = 0;
	if (n < 0)
	{
		len = write(fd, "-", 1);
		n = -n;
	}
	else if (subspec.force_sign)
		len = write(fd, "+", 1);
	if (len < 0)
		return (len);
	return (len + putll(n, fd));
}
