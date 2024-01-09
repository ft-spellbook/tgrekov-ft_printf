/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:22:38 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/09 18:06:57 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../subspec.h"
#include "../../utils/utils.h"

int	seq_char(va_list args, t_subspec subspec, int fd)
{
	char	c;
	int		res;

	res = 0;
	c = (char) va_arg(args, int);
	if (subspec.min_width > 1 && !subspec.left_justify && !wrap_err(
			repeat_str_n(subspec.pad_str, subspec.min_width - 1, fd), &res))
		return (-1);
	if (!wrap_err(write(fd, &c, 1), &res))
		return (-1);
	if (subspec.min_width > 1 && subspec.left_justify && !wrap_err(
			repeat_str_n(subspec.pad_str, subspec.min_width - 1, fd), &res))
		return (-1);
	return (res);
}
