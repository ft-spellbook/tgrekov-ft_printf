/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:36:38 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/16 02:46:24 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../subspec.h"
#include "../sequence.h"
#include "../../utils/internal_types.h"

t_usmallest	process_char(t_sequence seq, t_subspec subspec, int *fd, int total);

t_sequence	pre_percent(va_list args, t_sequence seq, t_subspec subspec)
{
	seq.data = (t_ubiggest) '%';
	if (subspec.min_width > 1)
		seq.pad_len = subspec.min_width - 1;
	seq.total_len = seq.pad_len + 1;
	seq.process = process_char;
	return (seq);
}
