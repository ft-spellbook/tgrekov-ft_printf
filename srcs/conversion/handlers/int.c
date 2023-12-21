/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:18:23 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/21 02:49:45 by tgrekov          ###   ########.fr       */
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

static int	left_subspec(t_subspec subspec, long long n, int unp_len, int fd)
{
	int	res_pad;
	int	res_sign;

	res_pad = 0;
	if (subspec.min_width && !subspec.left_justify && subspec.pad_str[0] == ' '
		&& !wrap_err(repeat_str_n(subspec.pad_str, unp_len, fd), &res_pad))
		return (-1);
	res_sign = 0;
	if (n < 0)
		res_sign = write(fd, "-", 1);
	else if (subspec.force_sign)
		res_sign = write(fd, "+", 1);
	else if (subspec.space_blank_sign)
		res_sign = write(fd, " ", 1);
	if (res_sign == -1)
		return (-1);
	if (subspec.min_width && !subspec.left_justify && subspec.pad_str[0] == '0'
		&& !wrap_err(repeat_str_n(subspec.pad_str, unp_len, fd), &res_pad))
		return (-1);
	return (res_pad + res_sign);
}

int	seq_int(va_list args, t_subspec subspec, int fd)
{
	long long	n;
	int			res_total;
	int			res_nbr;
	int			unp_len;

	n = getarg(args, subspec);
	unp_len = subspec.min_width - ll_len(n) - ((n > -1
				&& subspec.force_sign) || subspec.space_blank_sign);
	if (!wrap_err(left_subspec(subspec, n, unp_len, fd), &res_total))
		return (-1);
	if (n == -LLONG_MAX - 1LL)
	{
		n = (n + 1) * -1;
		res_nbr = putullbase((unsigned long long) n + 1ULL, "0123456789", fd);
	}
	else if (n < 0)
		res_nbr = putullbase(-n, "0123456789", fd);
	else
		res_nbr = putullbase(n, "0123456789", fd);
	if (res_nbr == -1)
		return (-1);
	if (subspec.min_width && subspec.left_justify
		&& !wrap_err(repeat_str_n(subspec.pad_str, unp_len, fd), &res_total))
		return (-1);
	return (res_total + res_nbr);
}
