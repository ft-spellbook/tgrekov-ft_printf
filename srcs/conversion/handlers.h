/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:29:00 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/09 17:44:34 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include <stdarg.h>
# include "subspec.h"

int		handle_sequence(const char **format, va_list args, int *fd, int total);
int		identify_sequence(const char **format, va_list args,
			t_subspec subspec, int *fd, int total);
int		seq_int(va_list args, t_subspec subspec, int fd);
int		seq_uint(va_list args, t_subspec subspec, int fd);
int		seq_uoct(va_list args, t_subspec subspec, int fd);
int		seq_uhex(va_list args, t_subspec subspec, int upper, int fd);
int		seq_char(va_list args, t_subspec subspec, int fd);
int		seq_string(va_list args, t_subspec subspec, int fd);
int		seq_pointer(va_list args, int fd);
int		seq_percent(int fd);
int		seq_ft_lst(va_list args, t_subspec subspec, int fd);
int		seq_set_fd(va_list args, int *fd);
int		seq_ft_lst(va_list args, t_subspec subspec, int fd);
int		seq_store(va_list args, t_subspec subspec, int total);

#endif //HANDLERS_H