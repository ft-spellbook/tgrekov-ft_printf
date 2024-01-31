/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:46:53 by tgrekov           #+#    #+#             */
/*   Updated: 2024/01/31 04:35:26 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEQUENCE_H
# define SEQUENCE_H

# include "subspec.h"
# include "../utils/internal_types.h"

typedef struct s_sequence
{
	char				specifier;
	t_subspec			subspec;
	char				*sign;
	t_ubiggest			data;
	int					total_len;
	int					pad_len;
	t_usmallest			(*process)(struct s_sequence, int *, int);
}	t_sequence;

#endif