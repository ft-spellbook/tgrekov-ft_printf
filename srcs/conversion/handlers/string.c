/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:25:24 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 19:45:52 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../../../libft/libft.h"

int	seq_string(va_list args, int fd)
{
	void	*str;

	str = va_arg(args, char *);
	if (!str)
		return (write(fd, "(null)", 6));
	return (write(fd, str, ft_strlen(str)));
}
