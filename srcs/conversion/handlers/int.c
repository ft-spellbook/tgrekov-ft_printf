/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:18:23 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/31 04:50:41 by tgrekov          ###   ########.fr       */
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

static unsigned long long	lltull(long long n)
{
	if (n == -LLONG_MAX - 1LL)
		return ((unsigned long long)(-(n + 1)) + 1ULL);
	if (n < 0)
		n = -n;
	return (n);
}

t_usmallest	process_uint(t_sequence seq, int *fd, int total);

void	pre_int(va_list args, t_sequence *seq)
{
	long long	n;

	if (seq->subspec.lenmod == hh)
		n = (signed char) va_arg(args, int);
	else if (seq->subspec.lenmod == h)
		n = (short) va_arg(args, int);
	else if (seq->subspec.lenmod == l)
		n = va_arg(args, long);
	else if (seq->subspec.lenmod == ll)
		n = va_arg(args, long long);
	else if (seq->subspec.lenmod == j)
		n = va_arg(args, intmax_t);
	else if (seq->subspec.lenmod == z)
		n = va_arg(args, size_t);
	else if (seq->subspec.lenmod == t)
		n = va_arg(args, t_ptrdiff_t);
	else
		n = va_arg(args, int);
	if (n < 0)
		seq->sign = "-";
	seq->data = lltull(n);
	seq->total_len = ull_len_base(seq->data, 10);
	if (seq->subspec.forced_sign && !seq->sign)
		seq->sign = seq->subspec.forced_sign;
	seq->process = process_uint;
}
