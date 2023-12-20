/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:31:15 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 17:16:08 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "def_sub.h"

int	intlen(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

//return (write(fd, "-9223372036854775808", 20));
int	putllbase(long long n, char *base, int base_len, int fd)
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
	if (n < 0)
	{
		res = write(fd, "-", 1);
		if (res == -1)
			return (-1);
		n = -n;
	}
	if (n > base_len - 1)
	{
		res = putllbase(n / base_len, base, base_len, fd);
		if (res == -1)
			return (-1);
	}
	if (write(fd, base + ((n - was_min) % base_len), 1) == -1)
		return (-1);
	return (res + 1);
}

int	putullbase(unsigned long long n, char *base, int base_len, int fd)
{
	int	res;

	res = 0;
	if (n > base_len - 1)
	{
		res = putullbase(n / base_len, base, base_len, fd);
		if (res == -1)
			return (-1);
	}
	if (write(fd, base + (n % base_len), 1) == -1)
		return (-1);
	return (res + 1);
}
