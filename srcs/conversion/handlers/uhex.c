/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:07:16 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 19:48:52 by tgrekov          ###   ########.fr       */
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

int	seq_uhex(va_list args, t_subspec subspec, int upper, int fd)
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
		res2 = putullbase(n, "0123456789ABCDEF", fd);
	else
		res2 = putullbase(n, "0123456789abcdef", fd);
	if (res2 == -1)
		return (-1);
	return (res + res2);
}
