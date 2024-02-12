/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:29:00 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/31 04:42:20 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include <stdarg.h>
# include "../sequence.h"
# include "../subspec.h"

void	pre_char(va_list args, t_sequence *seq);
void	pre_int(va_list args, t_sequence *seq);
void	pre_percent(va_list args, t_sequence *seq);
void	pre_ptr(va_list args, t_sequence *seq);
void	pre_set_fd(va_list args, t_sequence *seq);
void	pre_store(va_list args, t_sequence *seq);
void	pre_string(va_list args, t_sequence *seq);
void	pre_uhex(va_list args, t_sequence *seq);
void	pre_uint(va_list args, t_sequence *seq);
void	pre_uoct(va_list args, t_sequence *seq);

#endif