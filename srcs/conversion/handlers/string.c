/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:25:24 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/31 04:49:12 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../subspec.h"
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../../libft/libft.h"
#include "../../utils/internal_types.h"

t_usmallest	process_string(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (write(*fd, (char *) seq.data, seq.total_len - seq.pad_len));
}

void	pre_string(va_list args, t_sequence *seq)
{
	seq->data = (t_ubiggest) va_arg(args, char *);
	if (!seq->data)
		seq->data = (t_ubiggest) "(null)";
	seq->total_len = (int) ft_strlen((char *) seq->data);
	if (seq->subspec.precision > -1 && seq->subspec.precision < seq->total_len)
		seq->total_len = seq->subspec.precision;
	seq->process = process_string;
}
