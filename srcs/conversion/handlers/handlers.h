/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:29:00 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/16 01:50:04 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include <stdarg.h>
# include "../sequence.h"
# include "../subspec.h"

t_sequence	pre_char(va_list args, t_sequence sequence, t_subspec subspec);
t_sequence	pre_int(va_list args, t_sequence sequence, t_subspec subspec);
t_sequence	pre_percent(va_list args, t_sequence sequence, t_subspec subspec);
t_sequence	pre_pointer(va_list args, t_sequence sequence, t_subspec subspec);
t_sequence	pre_set_fd(va_list args, t_sequence sequence, t_subspec subspec);
t_sequence	pre_store(va_list args, t_sequence sequence, t_subspec subspec);
t_sequence	pre_string(va_list args, t_sequence sequence, t_subspec subspec);
t_sequence	pre_uhex(va_list args, t_sequence sequence, t_subspec subspec);
t_sequence	pre_uint(va_list args, t_sequence sequence, t_subspec subspec);
t_sequence	pre_uoct(va_list args, t_sequence sequence, t_subspec subspec);

#endif