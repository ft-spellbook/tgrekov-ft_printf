/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:41:27 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/09 17:44:42 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

int	identify_sequence(const char **format, va_list args,
			t_subspec subspec, int *fd, int total)
{
	if (**format == 'd' || **format == 'i')
		return (seq_int(args, subspec, *fd));
	if (**format == 'u')
		return (seq_uint(args, subspec, *fd));
	if (**format == 'o')
		return (seq_uoct(args, subspec, *fd));
	if (**format == 'x' || **format == 'X')
		return (seq_uhex(args, subspec, **format == 'X', *fd));
	if (**format == 'c')
		return (seq_char(args, subspec, *fd));
	if (**format == 's')
		return (seq_string(args, subspec, *fd));
	if (**format == 'p')
		return (seq_pointer(args, *fd));
	if (**format == '%')
		return (seq_percent(*fd));
	if (**format == 'n')
		return (seq_store(args, subspec, total));
	if (**format == '>')
		return (seq_set_fd(args, fd));
	if (**format == '{')
		return (seq_ft_lst(args, subspec, *fd));
	return (-1);
}
