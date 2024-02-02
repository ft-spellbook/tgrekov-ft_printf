/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:32:00 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/02 02:52:52 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int	ull_len_base(unsigned long long n, int base);
int	putullbase(unsigned long long n, char *base, int fd);
int	repeat_str_n(const char *str, int n, int fd);
int	wrap_err(int n, int *total);

#endif