/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:41:01 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 17:02:48 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "conversion/converters.h"
#include "utils/utils.h"
#include "../libft/libft.h"

static void	init_subspec(t_subspec *subspec)
{
	subspec->left_justify = 0;
	subspec->force_sign = 0;
	subspec->space_blank_sign = 0;
	subspec->force_decimal = 0;
	subspec->zero_pad = 0;
	subspec->min_width = 0;
	subspec->precision = 6;
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
	*format += intlen(res);
	return (res);
}

static void	parse_subspec(const char **format, t_subspec *subspec, va_list args)
{
	while (ft_strchr("-+ #0", **format))
	{
		if (**format == '-')
			subspec->left_justify = 1;
		else if (**format == '+')
			subspec->force_sign = 1;
		else if (**format == ' ')
			subspec->space_blank_sign = 1;
		else if (**format == '#')
			subspec->force_decimal = 1;
		else if (**format == '0')
			subspec->zero_pad = 1;
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
	int			res;

	init_subspec(&subspec);
	parse_subspec(format, &subspec, args);
	res = identify_conversion(format, args, subspec, fd, total);
	(*format)++;
	return (res);
}
