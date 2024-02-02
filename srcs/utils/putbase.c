/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:48:47 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/02 03:56:30 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "def_sub.h"
#include "../../libft/libft.h"

static int	_putullbase(unsigned long long n,
	char *base, unsigned int base_len, int fd)
{
	int	res;

	res = 0;
	if (n > base_len - 1)
	{
		res = _putullbase(n / base_len, base, base_len, fd);
		if (res == -1)
			return (-1);
	}
	if (write(fd, base + (n % base_len), 1) == -1)
		return (-1);
	return (res + 1);
}

int	putullbase(unsigned long long n, char *base, int fd)
{
	return (_putullbase(n, base, ft_strlen(base), fd));
}
