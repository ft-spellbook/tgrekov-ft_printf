/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:22:38 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 19:48:16 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	seq_char(va_list args, int fd)
{
	char	c;

	c = (char) va_arg(args, int);
	return (write(fd, &c, 1));
}
