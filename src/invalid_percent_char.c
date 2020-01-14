/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_percent_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:34:08 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/14 12:35:23 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int skip_invalid_percent_chars(char *format, int *i)
{
	while (format[*i] && format[*i] != '%')
		(*i)++;
	return (0);
}

static int is_invalid_char(char c)
{
	if (is_digit(c) || c == '-' || c == '.')
		return (0);
	return (1);
}

int invalid_percent_char(char *format, int i)
{
	while (format[i] && format[i] != '%')
	{
		if (is_conversion_char(format[i]))
			return (0);
		if (is_invalid_char(format[i]))
			return (1);
		++i;
	}
	if (!format[i])
		return (0);
	return (1);
}
