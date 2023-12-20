/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:22:38 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 17:03:15 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../converters.h"
#include "../../utils/def_sub.h"

int	c_char(va_list args, t_subspec subspec, int fd)
{
	char	c;

	if (subspec.lenmod == l)
		c = (char) va_arg(args, t_wint_t);
	else
		c = (char) va_arg(args, int);
	return (write(fd, &c, 1));
}
