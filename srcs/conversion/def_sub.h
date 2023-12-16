/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_sub.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:03:22 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/16 17:32:37 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_SUB_H
# define DEF_SUB_H

# ifdef _WCHAR_H_

typedef wint_t		t_wint_t;
# else

typedef int			t_wint_t;
# endif //_WCHAR_H_

# ifdef _PTRDIFF_T

typedef ptrdiff_t	t_ptrdiff_t;
# else

typedef long		t_ptrdiff_t;
# endif //_PTRDIFF_T

# ifndef LLONG_MAX

#  define LLONG_MAX 9223372036854775807LL
# endif //LLONG_MAX

#endif