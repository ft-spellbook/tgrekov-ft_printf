/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subspec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:20:17 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 19:20:34 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSPEC_H
# define SUBSPEC_H

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

#endif