/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:07:16 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/02 02:47:10 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"
#include "utils/handler_utils.h"

t_usmallest	process_uhex(t_sequence seq, int *fd, int total)
{
	(void) total;
	if (seq.specifier == 'X')
		return (print_uint_base(seq, *fd, "0123456789ABCDEF"));
	return (print_uint_base(seq, *fd, "0123456789abcdef"));
}

void	pre_uhex(va_list args, t_sequence *seq)
{
	seq->data = unsigned_arg(args, seq->subspec.lenmod);
	seq->total_len = ull_len_base(seq->data, 16);
	if (seq->subspec.precision > seq->total_len)
		seq->total_len = seq->subspec.precision;
	if (seq->subspec.force_decimal && seq->data)
	{
		seq->sign = "0x";
		if (seq->specifier == 'X')
			seq->sign = "0X";
	}
	seq->process = process_uhex;
}
