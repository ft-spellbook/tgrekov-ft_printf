/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:08:39 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/16 18:26:13 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	handle_sequence(const char **format, va_list args, int *fd, int total);
int	ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));

#endif