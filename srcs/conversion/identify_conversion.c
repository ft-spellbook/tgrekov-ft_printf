/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:41:27 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 17:04:54 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converters.h"

int	identify_conversion(const char **format, va_list args,
			t_subspec subspec, int *fd, int total)
{
	if (**format == 'd' || **format == 'i')
		return (c_int(args, subspec, *fd));
	if (**format == 'u')
		return (c_uint(args, subspec, *fd));
	if (**format == 'o')
		return (c_uoct(args, subspec, *fd));
	if (**format == 'x' || **format == 'X')
		return (c_uhex(args, subspec, **format == 'X', *fd));
	if (**format == 'c')
		return (c_char(args, subspec, *fd));
	if (**format == 's')
		return (c_string(args, subspec, *fd));
	if (**format == 'p')
		return (c_pointer(args, *fd));
	if (**format == '%')
		return (c_percent(*fd));
	if (**format == 'n')
		return (c_store(args, subspec, total));
	if (**format == '>')
		return (c_set_fd(args, fd));
	if (**format == '{')
		return (c_ft_lst(args, subspec, *fd));
	return (-1);
}
