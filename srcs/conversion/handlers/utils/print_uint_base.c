/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:31:45 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/02 02:42:16 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sequence.h"
#include "../../../utils/utils.h"
#include "../../../utils/internal_types.h"
#include "../../../../libft/libft.h"

t_usmallest	print_uint_base(t_sequence seq, int fd, char *base)
{
	int	res;

	res = 0;
	if (seq.subspec.precision > 0
		&& !wrap_err(repeat_str_n("0000000000", seq.subspec.precision
				- ull_len_base(seq.data, ft_strlen(base)), fd), &res))
		return (-1);
	if (!seq.subspec.precision && !seq.data)
		return (0);
	wrap_err(putullbase(seq.data, base, fd), &res);
	return (res);
}
