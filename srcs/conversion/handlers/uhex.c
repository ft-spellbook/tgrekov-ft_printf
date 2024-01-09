/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:07:16 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/04 17:26:13 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../subspec.h"
#include "../../utils/utils.h"
#include "../../utils/def_sub.h"

static unsigned long long	getarg(va_list args, t_subspec subspec)
{
	if (subspec.lenmod == hh)
		return ((unsigned char) va_arg(args, int));
	if (subspec.lenmod == h)
		return ((unsigned short) va_arg(args, int));
	if (subspec.lenmod == l)
		return (va_arg(args, unsigned long));
	if (subspec.lenmod == ll)
		return (va_arg(args, unsigned long long));
	if (subspec.lenmod == j)
		return (va_arg(args, uintmax_t));
	if (subspec.lenmod == z)
		return (va_arg(args, size_t));
	if (subspec.lenmod == t)
		return (va_arg(args, t_ptrdiff_t));
	return (va_arg(args, unsigned int));
}

static int	left_subspec(t_subspec subspec,
	unsigned long long n, int pad_n, int upper, int fd)
{
	int	res;

	res = 0;
	if (subspec.min_width && !subspec.left_justify && subspec.pad_str[0] == ' '
		&& !wrap_err(repeat_str_n(subspec.pad_str, pad_n, fd), &res))
		return (-1);
	if (subspec.min_width && !subspec.left_justify && subspec.pad_str[0] == '0'
		&& !wrap_err(repeat_str_n(subspec.pad_str, pad_n, fd), &res))
		return (-1);
	if (subspec.force_decimal && n && (
			(upper && !wrap_err(write(fd, "0X", 2), &res))
			|| (!upper && !wrap_err(write(fd, "0x", 2), &res))))
		return (-1);
	if (subspec.precision > 0)
		wrap_err(repeat_str_n("0000000000", subspec.precision
				- ull_len_base(n, 16), fd), &res);
	return (res);
}

int	seq_uhex(va_list args, t_subspec subspec, int upper, int fd)
{
	unsigned long long	n;
	int					res;
	int					pad_n;
	char				*base;

	n = getarg(args, subspec);
	pad_n = subspec.min_width - (subspec.force_decimal && n) * 2;
	if (subspec.precision == -1)
		pad_n -= ull_len_base(n, 16);
	else if (subspec.precision)
		pad_n -= max(ull_len_base(n, 16), subspec.precision);
	res = 0;
	if (!wrap_err(left_subspec(subspec, n, pad_n, upper, fd), &res))
		return (-1);
	base = "0123456789abcdef";
	if (upper)
		base = "0123456789ABCDEF";
	if (!wrap_err(putullbase(n, base, fd), &res))
		return (-1);
	if (subspec.min_width && subspec.left_justify)
		wrap_err(repeat_str_n(subspec.pad_str, pad_n, fd), &res);
	return (res);
}
