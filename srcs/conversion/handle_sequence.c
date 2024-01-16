/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:41:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/16 02:13:35 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "sequence.h"
#include "subspec.h"
#include "../utils/utils.h"
#include "../../libft/libft.h"

t_sequence	identify_sequence(char specifier, va_list args, t_subspec subspec);

static void	init_subspec(t_subspec *subspec)
{
	subspec->left_justify = 0;
	subspec->forced_sign = 0;
	subspec->force_decimal = 0;
	subspec->pad_str = "          ";
	subspec->min_width = 0;
	subspec->precision = -1;
	subspec->lenmod = none;
}

static void	parse_lenmod(const char **format, t_subspec *subspec)
{
	if (**format == 'h' && (*format)++)
	{
		subspec->lenmod = h;
		if (**format == 'h' && (*format)++)
			subspec->lenmod = hh;
	}
	else if (**format == 'l' && (*format)++)
	{
		subspec->lenmod = l;
		if (**format == 'l' && (*format)++)
			subspec->lenmod = ll;
	}
	else if (**format == 'j' && (*format)++)
		subspec->lenmod = j;
	else if (**format == 'z' && (*format)++)
		subspec->lenmod = z;
	else if (**format == 't' && (*format)++)
		subspec->lenmod = t;
	else if (**format == 'L' && (*format)++)
		subspec->lenmod = L;
}

static int	subspec_parse_width_or_precision(const char **format, va_list args)
{
	int	res;

	if (**format == '*')
	{
		(*format)++;
		return (va_arg(args, int));
	}
	res = ft_atoi(*format);
	if (ft_isdigit(**format))
		*format += ull_len_base(res, 10);
	return (res);
}

static void	parse_subspec(const char **format, t_subspec *subspec, va_list args)
{
	while (ft_strchr("-+ #0_", **format))
	{
		if (**format == '-')
			subspec->left_justify = 1;
		else if (**format == '+')
			subspec->forced_sign = "+";
		else if (**format == ' ')
			subspec->forced_sign = " ";
		else if (**format == '#')
			subspec->force_decimal = 1;
		else if (**format == '0')
			subspec->pad_str = "0000000000";
		else if (**format == '_')
			subspec->pad_str = va_arg(args, char *);
		(*format)++;
	}
	if (**format == '*' || ft_isdigit(**format))
		subspec->min_width = subspec_parse_width_or_precision(format, args);
	if (**format == '.')
	{
		(*format)++;
		subspec->precision = subspec_parse_width_or_precision(format, args);
	}
	parse_lenmod(format, subspec);
}

int	handle_sequence(const char **format, va_list args, int *fd, int total)
{
	t_subspec	subspec;
	t_sequence	seq;
	int			res;

	init_subspec(&subspec);
	parse_subspec(format, &subspec, args);
	seq = identify_sequence(**format, args, subspec);
	res = 0;
	if (seq.pad_len && !subspec.left_justify && subspec.pad_str[0] != '0'
		&& !wrap_err(repeat_str_n(subspec.pad_str, seq.pad_len, *fd), &res))
		return (-1);
	if (seq.sign && !wrap_err(write(*fd, &seq.sign, 1), &res))
		return (-1);
	if (seq.pad_len && !subspec.left_justify && subspec.pad_str[0] == '0'
		&& !wrap_err(repeat_str_n(subspec.pad_str, seq.pad_len, *fd), &res))
		return (-1);
	if (!wrap_err(seq.process(seq, subspec, fd, total + res), &res))
		return (-1);
	if (seq.pad_len && subspec.left_justify
		&& !wrap_err(repeat_str_n(subspec.pad_str, seq.pad_len, *fd), &res))
		return (-1);
	(*format)++;
	return (res);
}
