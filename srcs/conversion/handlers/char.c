/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:22:38 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/31 04:51:12 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../subspec.h"
#include "../sequence.h"
#include "../../utils/utils.h"
#include "../../utils/internal_types.h"

t_usmallest	process_char(t_sequence seq, int *fd, int total)
{
	(void) total;
	return (write(*fd, (char *) &seq.data, 1));
}

void	pre_char(va_list args, t_sequence *seq)
{
	seq->data = (t_ubiggest) va_arg(args, int);
	seq->total_len = 1;
	seq->process = process_char;
}
