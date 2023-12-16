/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:29:00 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/16 18:25:36 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTERS_H
# define CONVERTERS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "def_sub.h"

typedef enum e_lenmod
{
	none	= 0,
	hh		= 1,
	h		= 2,
	l		= 3,
	ll		= 4,
	j		= 5,
	z		= 6,
	t		= 7,
	L		= 8
}	t_lenmod;

typedef struct s_subspec
{
	int			left_justify;
	int			force_sign;
	int			space_blank_sign;
	int			force_decimal;
	int			zero_pad;
	int			min_width;
	int			precision;
	t_lenmod	lenmod;
}		t_subspec;

int		putuhexll(unsigned long long n, int upper);

int		identify_conversion(const char **format, va_list args,
			t_subspec subspec, int *fd, int total);
int		c_int(va_list args, t_subspec subspec, int fd);
int		c_uint(va_list args, t_subspec subspec, int fd);
int		c_uoct(va_list args, t_subspec subspec, int fd);
int		c_uhex(va_list args, t_subspec subspec, int upper, int fd);
//int		c_float(va_list args, t_subspec subspec, int upper);
int		c_char(va_list args, t_subspec subspec, int fd);
int		c_string(va_list args, t_subspec subspec, int fd);
int		c_pointer(va_list args, t_subspec subspec, int fd);
int		c_percent(int fd);
int		c_ft_lst(va_list args, t_subspec subspec, int fd);
int		c_set_fd(va_list args, int *fd);
int		c_ft_lst(va_list args, t_subspec subspec, int fd);
int		c_store(va_list args, t_subspec subspec, int total);

#endif //CONVERTERS_H