/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:25:24 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/16 02:48:50 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../subspec.h"
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../../libft/libft.h"
#include "../../utils/internal_types.h"

t_usmallest	process_string(t_sequence seq,
	t_subspec subspec, int *fd, int total)
{
	(void) subspec;
	(void) total;
	return (write(*fd, (char *) seq.data, seq.total_len - seq.pad_len));
}

t_sequence	pre_string(va_list args, t_sequence seq, t_subspec subspec)
{
	seq.data = (t_ubiggest) va_arg(args, char *);
	if (!seq.data)
		seq.data = (t_ubiggest) "(null)";
	seq.total_len = (int) ft_strlen((char *) seq.data);
	if (subspec.precision > -1 && subspec.precision < seq.total_len)
		seq.total_len = subspec.precision;
	if (subspec.min_width > seq.total_len)
		seq.pad_len = subspec.min_width - seq.total_len;
	seq.total_len += seq.pad_len;
	seq.process = process_string;
	return (seq);
}
