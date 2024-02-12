/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:40:21 by tgrekov           #+#    #+#             */
/*   Updated: 2024/02/02 04:12:41 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_TYPES_H
# define INTERNAL_TYPES_H

typedef long long			t_biggest;
typedef unsigned long long	t_ubiggest;
# define T_BIGGEST_MAX 9223372036854775807LL

# ifdef _WCHAR_H_

typedef wint_t				t_wint_t;
# else

typedef int					t_wint_t;
# endif //_WCHAR_H_

# ifdef _PTRDIFF_T

typedef ptrdiff_t			t_ptrdiff_t;
# else

typedef long				t_ptrdiff_t;
# endif //_PTRDIFF_T

#endif