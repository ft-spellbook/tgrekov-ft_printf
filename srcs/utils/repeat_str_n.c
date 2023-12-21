/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_str_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:26:03 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 22:17:24 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

static int	_repeat_str_n(const char *str, int n, int strlen, int fd)
{
	int	res;
	int	res2;

	res = 0;
	if (n > strlen)
	{
		res = _repeat_str_n(str, n - strlen, strlen, fd);
		if (res == -1)
			return (-1);
		n = strlen;
	}
	res2 = write(fd, str, n);
	if (res2 == -1)
		return (-1);
	return (res + res2);
}

int	repeat_str_n(const char *str, int n, int fd)
{
	return (_repeat_str_n(str, n, ft_strlen(str), fd));
}
