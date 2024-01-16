/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:58:03 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/16 02:36:27 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../subspec.h"
#include "../sequence.h"
#include "../../utils/internal_types.h"

t_usmallest	process_set_fd(t_sequence seq,
	t_subspec subspec, int *fd, int total)
{
	(void) subspec;
	(void) total;
	*fd = (int) seq.data;
	return (0);
}

t_sequence	pre_set_fd(va_list args, t_sequence seq, t_subspec subspec)
{
	seq.data = (t_ubiggest) va_arg(args, int);
	seq.process = process_set_fd;
	return (seq);
}
