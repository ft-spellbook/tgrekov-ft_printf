/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:03:16 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 20:32:34 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "conversion/handlers.h"

static int	do_segment(const char **format, va_list args, int *fd, int total)
{
	char	*seq_start;
	int		res;
	int		seq_res;

	seq_start = ft_strchr(*format, '%');
	if (!seq_start)
	{
		res = write(*fd, *format, ft_strlen(*format));
		*format += res;
	}
	else
	{
		res = 0;
		if (seq_start != *format)
			res = write(*fd, *format, seq_start - *format);
		*format = seq_start + 1;
		if (res > -1)
		{
			seq_res = handle_sequence(format, args, fd, total);
			if (seq_res > -1)
				res += seq_res;
			else
				res = -1;
		}
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		printed;
	int		fd;

	if (!format)
		return (-1);
	fd = STDOUT_FILENO;
	va_start(args, format);
	total = 0;
	while (*format && total > -1)
	{
		printed = do_segment(&format, args, &fd, total);
		if (printed < 0)
			total = -1;
		else
			total += printed;
	}
	va_end(args);
	return (total);
}


//#include <stdio.h>
/*
int	main(void)
{
	ft_printf("%d\n", -10);
	//printf("%x\n", 10);
}
*/