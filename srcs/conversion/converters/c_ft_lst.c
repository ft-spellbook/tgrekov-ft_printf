/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ft_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:13:20 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/16 18:06:36 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../converters.h"
#include "../../../libft/libft.h"

//content, index, fd

int	c_ft_lst(va_list args, t_subspec subspec, int fd)
{
	int		res;
	int		i;
	t_list	*lst;
	int		(*lst_print_content)(void *, int, int);

	lst_print_content = va_arg(args, void *);
	lst = va_arg(args, t_list *);
	i = 0;
	while (lst && res > -1)
	{
		res = lst_print_content(lst->content, i++, fd);
		lst = lst->next;
	}
	return (res);
}
