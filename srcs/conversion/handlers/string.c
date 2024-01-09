/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:25:24 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/09 18:12:19 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../subspec.h"
#include "../../utils/utils.h"
#include "../../../libft/libft.h"

int	seq_string(va_list args, t_subspec subspec, int fd)
{
	char	*str;
	size_t	len;
	int		res;

	res = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (subspec.precision > -1 && (size_t) subspec.precision < len)
		len = subspec.precision;
	if ((size_t) subspec.min_width > len && !subspec.left_justify && !wrap_err(
			repeat_str_n(subspec.pad_str, subspec.min_width - len, fd), &res))
		return (-1);
	if (!wrap_err(write(fd, str, len), &res))
		return (-1);
	if ((size_t) subspec.min_width > len && subspec.left_justify && !wrap_err(
			repeat_str_n(subspec.pad_str, subspec.min_width - len, fd), &res))
		return (-1);
	return (res);
}
