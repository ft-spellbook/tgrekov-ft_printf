/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:18:34 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/16 02:36:02 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "../subspec.h"
#include "../sequence.h"
#include "../../utils/def_sub.h"
#include "../../utils/internal_types.h"

t_usmallest	process_store(t_sequence seq, t_subspec subspec, int *fd, int total)
{
	if (subspec.lenmod == hh)
		*((signed char *) seq.data) = total;
	else if (subspec.lenmod == h)
		*((short *) seq.data) = total;
	else if (subspec.lenmod == l)
		*((long *) seq.data) = total;
	else if (subspec.lenmod == ll)
		*((long long *) seq.data) = total;
	else if (subspec.lenmod == j)
		*((intmax_t *) seq.data) = total;
	else if (subspec.lenmod == z)
		*((size_t *) seq.data) = total;
	else if (subspec.lenmod == t)
		*((t_ptrdiff_t *) seq.data) = total;
	else
		*((int *) seq.data) = total;
	return (0);
}

t_sequence	pre_store(va_list args, t_sequence seq, t_subspec subspec)
{
	if (subspec.lenmod == hh)
		seq.data = (t_ubiggest) va_arg(args, int *);
	else if (subspec.lenmod == h)
		seq.data = (t_ubiggest) va_arg(args, int *);
	else if (subspec.lenmod == l)
		seq.data = (t_ubiggest) va_arg(args, long *);
	else if (subspec.lenmod == ll)
		seq.data = (t_ubiggest) va_arg(args, long long *);
	else if (subspec.lenmod == j)
		seq.data = (t_ubiggest) va_arg(args, intmax_t *);
	else if (subspec.lenmod == z)
		seq.data = (t_ubiggest) va_arg(args, size_t *);
	else if (subspec.lenmod == t)
		seq.data = (t_ubiggest) va_arg(args, t_ptrdiff_t *);
	else
		seq.data = (t_ubiggest) va_arg(args, int *);
	seq.process = process_store;
	return (seq);
}
