/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:03:16 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/21 03:08:25 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "utils/utils.h"
#include "conversion/handlers.h"

static int	do_segment(const char **format, va_list args, int *fd, int total)
{
	char	*seq_start;
	int		res;
	int		print_len;

	seq_start = ft_strchr(*format, '%');
	if (!seq_start)
		print_len = ft_strlen(*format);
	else
		print_len = seq_start - *format;
	res = 0;
	if (print_len && seq_start != *format)
		res = write(*fd, *format, print_len);
	*format += res;
	if (res != -1 && seq_start)
	{
		(*format)++;
		add_err(handle_sequence(format, args, fd, total), &res);
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		fd;

	if (!format)
		return (-1);
	fd = STDOUT_FILENO;
	va_start(args, format);
	total = 0;
	while (total > -1 && *format)
		add_err(do_segment(&format, args, &fd, total), &total);
	va_end(args);
	return (total);
}


#include <stdio.h>

int	main(void)
{
	ft_printf("%d\n", -200000);
	//printf("%+6d\n", 10);
}
