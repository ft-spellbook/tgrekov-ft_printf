/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:13:20 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/20 20:04:55 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../subspec.h"
#include "../../../libft/libft.h"

//t_list *, subspec, index, fd

int	seq_ft_lst(va_list args, t_subspec subspec, int fd)
{
	int		res;
	int		i;
	t_list	*lst;
	int		(*lst_print_content)(t_list *, t_subspec, int, int);

	lst_print_content = va_arg(args, void *);
	lst = va_arg(args, t_list *);
	i = 0;
	while (lst && res > -1)
	{
		res = lst_print_content(lst, subspec, i++, fd);
		lst = lst->next;
	}
	return (res);
}
