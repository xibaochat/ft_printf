/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_invalide_char_in_flag.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 03:43:54 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/04 04:57:16 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	has_invalide_char_in_flag(char *format, int i)
{
	int init;

	init = i;
	while (format[i] && !is_conversion_char(format[i]))
	{
		if (format[i] == '%' && i != init)
			return (0);
		if (!is_allowed_char_in_flag(format[i]))
			return (1);
		i++;
	}
	return (0);
}
