/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:18:23 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 19:32:05 by tgrekov          ###   ########.fr       */
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

int	seq_int(va_list args, t_subspec subspec, int fd)
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
	res2 = putllbase(n, "0123456789", fd);
	if (res2 == -1)
		return (-1);
	return (res + res2);
}
