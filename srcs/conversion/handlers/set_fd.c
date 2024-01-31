/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:58:03 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/31 04:49:27 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../subspec.h"
#include "../sequence.h"
#include "../../utils/internal_types.h"

t_usmallest	process_set_fd(t_sequence seq, int *fd, int total)
{
	(void) total;
	*fd = (int) seq.data;
	return (0);
}

void	pre_set_fd(va_list args, t_sequence *seq)
{
	seq->data = (t_ubiggest) va_arg(args, int);
	seq->process = process_set_fd;
}
