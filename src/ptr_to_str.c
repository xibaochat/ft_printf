/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 03:12:31 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/04 03:12:51 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ptr_to_str(void *ptr)
{
	uintmax_t	p;
	char		*new;

	p = (uintmax_t)ptr;
	if (!p)
	{
		new = ft_strnew(6);
		ft_strcat(new, "(nil)");
		return (new);
	}
	return (ft_trans_to_x(p));
}
