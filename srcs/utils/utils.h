/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:32:00 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/21 03:09:14 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int	ll_len(long long n);
int	putullbase(unsigned long long n, char *base, int fd);
int	repeat_str_n(const char *str, int n, int fd);
int	add_err(int n, int *total);

#endif