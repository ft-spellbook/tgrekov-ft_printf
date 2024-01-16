/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:41:27 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/16 01:42:33 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers/handlers.h"
#include "sequence.h"

static t_sequence	init_sequence(char specifier)
{
	t_sequence	sequence;

	sequence.specifier = specifier;
	sequence.sign = 0;
	sequence.total_len = 0;
	sequence.pad_len = 0;
	return (sequence);
}

t_sequence	identify_sequence(char specifier, va_list args, t_subspec subspec)
{
	t_sequence	sequence;

	sequence = init_sequence(specifier);
	if (specifier == 'd' || specifier == 'i')
		return (pre_int(args, sequence, subspec));
	if (specifier == 'u')
		return (pre_uint(args, sequence, subspec));
	if (specifier == 'o')
		return (pre_uoct(args, sequence, subspec));
	if (specifier == 'x' || specifier == 'X')
		return (pre_uhex(args, sequence, subspec));
	if (specifier == 'c')
		return (pre_char(args, sequence, subspec));
	if (specifier == 's')
		return (pre_string(args, sequence, subspec));
	if (specifier == 'p')
		return (pre_pointer(args, sequence, subspec));
	if (specifier == '%')
		return (pre_percent(args, sequence, subspec));
	if (specifier == 'n')
		return (pre_store(args, sequence, subspec));
	if (specifier == '>')
		return (pre_set_fd(args, sequence, subspec));
	sequence.specifier = 0;
	return (sequence);
}
