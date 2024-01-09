/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:18:23 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/09 17:40:20 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../subspec.h"
#include "../../utils/utils.h"
#include "../../utils/def_sub.h"

static long long	getarg(va_list args, t_subspec subspec)
{
	if (subspec.lenmod == hh)
		return ((signed char) va_arg(args, int));
	if (subspec.lenmod == h)
		return ((short) va_arg(args, int));
	if (subspec.lenmod == l)
		return (va_arg(args, long));
	if (subspec.lenmod == ll)
		return (va_arg(args, long long));
	if (subspec.lenmod == j)
		return (va_arg(args, intmax_t));
	if (subspec.lenmod == z)
		return (va_arg(args, size_t));
	if (subspec.lenmod == t)
		return (va_arg(args, t_ptrdiff_t));
	return (va_arg(args, int));
}

static unsigned long long	lltull(long long n)
{
	if (n == -LLONG_MAX - 1LL)
		return ((unsigned long long)((n + 1) * -1) + 1ULL);
	else if (n < 0)
		return (-n);
	return (n);
}

static int	left_subspec(t_subspec subspec, long long n, int pad_n, int fd)
{
	int	res_pad;
	int	res_sign;

	res_pad = 0;
	if (subspec.min_width && !subspec.left_justify && subspec.pad_str[0] == ' '
		&& !wrap_err(repeat_str_n(subspec.pad_str, pad_n, fd), &res_pad))
		return (-1);
	res_sign = 0;
	if (n < 0)
		res_sign = write(fd, "-", 1);
	else if (subspec.forced_sign)
		res_sign = write(fd, subspec.forced_sign, 1);
	if (res_sign == -1)
		return (-1);
	if (subspec.min_width && !subspec.left_justify && subspec.pad_str[0] == '0'
		&& !wrap_err(repeat_str_n(subspec.pad_str, pad_n, fd), &res_pad))
		return (-1);
	if (subspec.precision > 0 && !wrap_err(
			repeat_str_n("0000000000", subspec.precision
				- ull_len_base(lltull(n), 10), fd), &res_pad))
		return (-1);
	return (res_pad + res_sign);
}

int	seq_int(va_list args, t_subspec subspec, int fd)
{
	long long			n;
	unsigned long long	un;
	int					res_total;
	int					pad_n;

	n = getarg(args, subspec);
	un = lltull(n);
	pad_n = subspec.min_width - (n < 0 || subspec.forced_sign);
	if (subspec.precision == -1)
		pad_n -= ull_len_base(un, 10);
	else if (subspec.precision)
		pad_n -= max(ull_len_base(un, 10), subspec.precision);
	res_total = 0;
	if (!wrap_err(left_subspec(subspec, n, pad_n, fd), &res_total))
		return (-1);
	if (!(!un && !subspec.precision)
		&& !wrap_err(putullbase(un, "0123456789", fd), &res_total))
		return (-1);
	if (subspec.min_width && subspec.left_justify
		&& !wrap_err(repeat_str_n(subspec.pad_str, pad_n, fd), &res_total))
		return (-1);
	return (res_total);
}
