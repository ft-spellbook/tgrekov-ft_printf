/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:25:24 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/16 18:04:47 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../converters.h"
#include "../../../libft/libft.h"

int	c_string(va_list args, t_subspec subspec, int fd)
{
	void	*str;
	size_t	len;

	if (subspec.lenmod == l)
		str = va_arg(args, wchar_t *);
	else
		str = va_arg(args, char *);
	if (!str)
		return (write(fd, "(null)", 6));
	len = ft_strlen(str);
	return (write(fd, str, len));
}
