/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:18:23 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 16:53:32 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../converters.h"
#include "../../utils/utils.h"
#include "../../utils/def_sub.h"

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
	int			res;
	int			res2;

	n = getarg(args, subspec);
	res = 0;
	if (n > -1 && subspec.force_sign)
		res = write(fd, "+", 1);
	if (res == -1)
		return (-1);
	res2 = putllbase(n, "0123456789", 10, fd);
	if (res2 == -1)
		return (-1);
	return (res + res2);
}
