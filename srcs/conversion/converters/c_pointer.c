/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:38:51 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 17:08:42 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../converters.h"
#include "../../utils/utils.h"

int	c_pointer(va_list args, int fd)
{
	unsigned long long	n;

	n = (unsigned long long) va_arg(args, void *);
	if (write(fd, "0x", 2) == -1)
		return (-1);
	return (putullbase(n, "abcdef0123456789", 16, fd) + 2);
}
