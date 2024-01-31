/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:07:16 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/31 04:47:51 by tgrekov          ###   ########.fr       */
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

t_usmallest	process_uhex(t_sequence seq, int *fd, int total)
{
	(void) total;
	if (seq.specifier == 'X')
		return (putullbase(seq.data, "0123456789ABCDEF", *fd));
	return (putullbase(seq.data, "0123456789abcdef", *fd));
}

void	pre_uhex(va_list args, t_sequence *seq)
{
	if (seq->subspec.lenmod == hh)
		seq->data = (unsigned char) va_arg(args, unsigned int);
	else if (seq->subspec.lenmod == h)
		seq->data = (unsigned short) va_arg(args, unsigned int);
	else if (seq->subspec.lenmod == l)
		seq->data = va_arg(args, unsigned long);
	else if (seq->subspec.lenmod == ll)
		seq->data = va_arg(args, unsigned long long);
	else if (seq->subspec.lenmod == j)
		seq->data = va_arg(args, uintmax_t);
	else if (seq->subspec.lenmod == z)
		seq->data = va_arg(args, size_t);
	else if (seq->subspec.lenmod == t)
		seq->data = va_arg(args, t_ptrdiff_t);
	else
		seq->data = va_arg(args, unsigned int);
	seq->total_len = ull_len_base(seq->data, 16);
	if (seq->subspec.force_decimal && seq->data)
	{
		seq->sign = "0x";
		if (seq->specifier == 'X')
			seq->sign = "0X";
	}
	seq->process = process_uhex;
}
