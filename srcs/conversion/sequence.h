/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:46:53 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/16 02:13:19 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEQUENCE_H
# define SEQUENCE_H

# include <stdarg.h>
# include "subspec.h"
# include "../utils/internal_types.h"

typedef struct s_sequence
{
	char				specifier;
	char				sign;
	t_ubiggest			data;
	int					total_len;
	int					pad_len;
	t_usmallest			(*process)(struct s_sequence, t_subspec, int *, int);
}	t_sequence;

#endif