/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:50:06 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/16 03:29:08 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../subspec.h"
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/def_sub.h"
#include "../../utils/internal_types.h"

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
	unsigned long long n, int pad_n, int fd)
{
	int	res;

	res = 0;
	if (subspec.min_width && !subspec.left_justify && subspec.pad_str[0] == ' '
		&& !wrap_err(repeat_str_n(subspec.pad_str, pad_n, fd), &res))
		return (-1);
	if (subspec.forced_sign
		&& !wrap_err(write(fd, subspec.forced_sign, 1), &res))
		return (-1);
	if (subspec.min_width && !subspec.left_justify && subspec.pad_str[0] == '0'
		&& !wrap_err(repeat_str_n(subspec.pad_str, pad_n, fd), &res))
		return (-1);
	if (subspec.precision > 0)
		wrap_err(repeat_str_n("0000000000", subspec.precision
				- ull_len_base(n, 10), fd), &res);
	return (res);
}

int	seq_uint(va_list args, t_subspec subspec, int fd)
{
	unsigned long long	n;
	int					res;
	int					pad_n;

	n = getarg(args, subspec);
	pad_n = subspec.min_width - !!subspec.forced_sign;
	if (subspec.precision == -1)
		pad_n -= ull_len_base(n, 10);
	else if (subspec.precision)
		pad_n -= max(ull_len_base(n, 10), subspec.precision);
	res = 0;
	if (!wrap_err(left_subspec(subspec, n, pad_n, fd), &res))
		return (-1);
	if (!wrap_err(putullbase(n, "0123456789", fd), &res))
		return (-1);
	if (subspec.min_width && subspec.left_justify)
		wrap_err(repeat_str_n(subspec.pad_str, pad_n, fd), &res);
	return (res);
}

t_usmallest	process_uint(t_sequence seq, t_subspec subspec, int *fd, int total)
{
	(void) total;
	return (write(*fd, (char *) &seq.data, 1));
}

t_sequence	pre_uint(va_list args, t_sequence seq, t_subspec subspec)
{
	if (subspec.lenmod == hh)
		seq.data = (unsigned char) va_arg(args, unsigned int);
	else if (subspec.lenmod == h)
		seq.data = (unsigned short) va_arg(args, unsigned int);
	else if (subspec.lenmod == l)
		seq.data = va_arg(args, unsigned long);
	else if (subspec.lenmod == ll)
		seq.data = va_arg(args, unsigned long long);
	else if (subspec.lenmod == j)
		seq.data = va_arg(args, uintmax_t);
	else if (subspec.lenmod == z)
		seq.data = va_arg(args, size_t);
	else if (subspec.lenmod == t)
		seq.data = va_arg(args, t_ptrdiff_t);
	else
		seq.data = va_arg(args, unsigned int);
	seq.total_len = ull_len_base(seq.data, 10) + !!subspec.forced_sign;
	if (subspec.min_width > seq.total_len)
		seq.pad_len = subspec.min_width - seq.total_len;
	seq.total_len += seq.pad_len;
	if (subspec.forced_sign)
		seq.sign = subspec.forced_sign;
	seq.process = process_uint;
	return (seq);
}
