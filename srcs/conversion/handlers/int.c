/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:18:23 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/02 03:56:56 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/def_sub.h"
#include "../../utils/internal_types.h"

int	process_uint(t_sequence seq, int *fd, int total);

static long long	signed_arg(va_list args, t_sequence *seq)
{
	if (seq->subspec.lenmod == hh)
		return ((signed char) va_arg(args, int));
	if (seq->subspec.lenmod == h)
		return ((short) va_arg(args, int));
	if (seq->subspec.lenmod == l)
		return (va_arg(args, long));
	if (seq->subspec.lenmod == ll)
		return (va_arg(args, long long));
	if (seq->subspec.lenmod == j)
		return (va_arg(args, intmax_t));
	if (seq->subspec.lenmod == z)
		return (va_arg(args, size_t));
	if (seq->subspec.lenmod == t)
		return (va_arg(args, t_ptrdiff_t));
	return (va_arg(args, int));
}

static t_ubiggest	lltull(long long n)
{
	if (n == -LLONG_MAX - 1LL)
		return ((t_ubiggest)(-(n + 1)) + 1ULL);
	if (n < 0)
		n = -n;
	return (n);
}

void	pre_int(va_list args, t_sequence *seq)
{
	long long	n;

	n = signed_arg(args, seq);
	if (n < 0)
		seq->sign = "-";
	seq->data = lltull(n);
	seq->total_len = ull_len_base(seq->data, 10)
		- (!seq->subspec.precision && !seq->data);
	if (seq->subspec.precision > seq->total_len)
		seq->total_len = seq->subspec.precision;
	if (seq->subspec.precision != -1)
		seq->subspec.pad_str = "          ";
	if (seq->subspec.forced_sign && !seq->sign)
		seq->sign = seq->subspec.forced_sign;
	seq->process = process_uint;
}
