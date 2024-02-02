/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:37:35 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/02 02:45:48 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_UTILS_H
# define HANDLER_UTILS_H

# include <stdarg.h>
# include "../../../utils/internal_types.h"
# include "../../sequence.h"

t_ubiggest	unsigned_arg(va_list args, t_lenmod lenmod);
t_usmallest	print_uint_base(t_sequence seq, int fd, char *base);

#endif