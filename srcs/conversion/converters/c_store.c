/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_store.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:18:34 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/16 18:25:03 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../converters.h"
#include "../../../libft/libft.h"

int	c_store(va_list args, t_subspec subspec, int total)
{
	if (subspec.lenmod == hh)
		*((signed char *) va_arg(args, int *)) = total;
	else if (subspec.lenmod == h)
		*((short *) va_arg(args, int *)) = total;
	else if (subspec.lenmod == l)
		*(va_arg(args, long *)) = total;
	else if (subspec.lenmod == ll)
		*(va_arg(args, long long *)) = total;
	else if (subspec.lenmod == j)
		*(va_arg(args, intmax_t *)) = total;
	else if (subspec.lenmod == z)
		*(va_arg(args, size_t *)) = total;
	else if (subspec.lenmod == t)
		*(va_arg(args, t_ptrdiff_t *)) = total;
	else
		*(va_arg(args, int *)) = total;
	return (0);
}
