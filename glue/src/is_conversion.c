/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:03:30 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/28 16:35:27 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int invalid_flags(char *format, int *i)
{
	/*
	  MUST CHECK THE VALIDITY OF THE FLAGS
	*/
	while (!is_conversion_char(format[*i]) ||
		   format[*i] == '.' ||
		   format[*i] == '-')
		   ++(*i);
	return (0);
}

int is_conversion(char *format, int *i_format)
{
	int i;

	i = *i_format;
	if (format[++i] == '%')
	{
		++(*i_format);
		return (0);
	}
	if (invalid_flags(format, &i))
		return (0);
	if (is_conversion_char(format[i]))
		return (1);
	return (0);
}
