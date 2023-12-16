/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:38:51 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/16 18:06:03 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../converters.h"

int	c_pointer(va_list args, t_subspec subspec, int fd)
{
	(void) subspec;
	if (write(fd, "0x", 2) == -1)
		return (-1);
	return (putuhexll((unsigned long long) va_arg(args, void *), 0) + 2);
}
