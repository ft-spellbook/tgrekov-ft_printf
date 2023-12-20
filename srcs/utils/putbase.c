/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:48:47 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 17:49:12 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "def_sub.h"
#include "../../libft/libft.h"

static int	_putllbase(long long n, char *base, int base_len, int fd)
{
	int	res;
	int	was_min;

	was_min = 0;
	if (n == -LLONG_MAX - 1LL)
	{
		was_min = 1;
		n++;
	}
	res = 0;
	if (n > base_len - 1)
	{
		res = _putllbase(n / base_len, base, base_len, fd);
		if (res == -1)
			return (-1);
	}
	if (write(fd, base + ((n - was_min) % base_len), 1) == -1)
		return (-1);
	return (res + 1);
}

//return (write(fd, "-9223372036854775808", 20));
int	putllbase(long long n, char *base, int fd)
{
	int	res;
	int	was_neg;

	was_neg = 0;
	if (n < 0)
	{
		was_neg = 1;
		if (write(fd, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	res = _putllbase(n, base, ft_strlen(base), fd);
	if (res == -1)
		return (-1);
	return (res + was_neg);
}

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
