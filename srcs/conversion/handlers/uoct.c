/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uoct.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:59:50 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/31 04:47:20 by tgrekov          ###   ########.fr       */
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

t_usmallest	process_uoct(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (putullbase(seq.data, "01234567", *fd));
}

void	pre_uoct(va_list args, t_sequence *seq)
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
	seq->total_len = ull_len_base(seq->data, 8);
	if (seq->subspec.force_decimal && seq->data)
		seq->sign = "0";
	seq->process = process_uoct;
}
