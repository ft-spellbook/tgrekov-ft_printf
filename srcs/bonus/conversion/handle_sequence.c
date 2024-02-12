/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:41:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/12 06:36:27 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "sequence.h"
#include "../utils/utils.h"
#include "../../../libft/libft.h"

void	init_subspec(t_subspec *subspec);
void	identify_sequence(va_list args, t_sequence *seq);
void	parse_subspec(const char **format, t_subspec *subspec, va_list args);

static int	print(t_sequence seq, int *fd, int total)
{
	int	res;

	res = 0;
	if (seq.pad_len && !seq.subspec.left_justify
		&& seq.subspec.pad_str[0] != '0'
		&& !wrap_err(repeat_str_n(seq.subspec.pad_str, seq.pad_len, *fd), &res))
		return (-1);
	if (seq.sign && !wrap_err(write(*fd, seq.sign, ft_strlen(seq.sign)), &res))
		return (-1);
	if (seq.pad_len && !seq.subspec.left_justify
		&& seq.subspec.pad_str[0] == '0'
		&& !wrap_err(repeat_str_n(seq.subspec.pad_str, seq.pad_len, *fd), &res))
		return (-1);
	if (!wrap_err(seq.process(seq, fd, total + res), &res))
		return (-1);
	if (seq.pad_len && seq.subspec.left_justify
		&& !wrap_err(repeat_str_n(seq.subspec.pad_str, seq.pad_len, *fd), &res))
		return (-1);
	return (res);
}

int	handle_sequence(const char **format, va_list args, int *fd, int total)
{
	t_sequence	seq;

	init_subspec(&seq.subspec);
	parse_subspec(format, &seq.subspec, args);
	seq.specifier = **format;
	identify_sequence(args, &seq);
	if (!seq.specifier)
		return (-1);
	if (seq.sign)
		seq.total_len += ft_strlen(seq.sign);
	if (seq.subspec.min_width > seq.total_len)
		seq.pad_len = seq.subspec.min_width - seq.total_len;
	seq.total_len += seq.pad_len;
	(*format)++;
	return (print(seq, fd, total));
}