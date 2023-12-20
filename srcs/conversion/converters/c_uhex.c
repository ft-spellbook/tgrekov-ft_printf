/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_uhex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:07:16 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 16:57:43 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../converters.h"
#include "../../utils/utils.h"
#include "../../utils/def_sub.h"

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
	int					res;
	int					res2;

	n = getarg(args, subspec);
	res = 0;
	if (subspec.force_sign)
		res = write(fd, "+", 1);
	if (res == -1)
		return (-1);
	if (upper)
		res2 = putullbase(n, "ABCDEF0123456789", 16, fd);
	else
		res2 = putullbase(n, "abcdef0123456789", 16, fd);
	if (res2 == -1)
		return (-1);
	return (res + res2);
}
