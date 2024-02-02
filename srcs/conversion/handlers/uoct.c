/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uoct.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:59:50 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/02 02:46:56 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"
#include "utils/handler_utils.h"

t_usmallest	process_uoct(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (print_uint_base(seq, *fd, "01234567"));
}

void	pre_uoct(va_list args, t_sequence *seq)
{
	seq->data = unsigned_arg(args, seq->subspec.lenmod);
	seq->total_len = ull_len_base(seq->data, 8);
	if (seq->subspec.precision > seq->total_len)
		seq->total_len = seq->subspec.precision;
	if (seq->subspec.force_decimal && seq->data)
		seq->sign = "0";
	seq->process = process_uoct;
}
