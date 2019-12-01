/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:36:57 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/30 05:28:00 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char *get_arg_as_str(va_list *ap, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(*ap, int)));
	else if (c == 's')
		return va_arg(*ap, char *);
	else if (c == 'c')
		return (char_to_str(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_itoa(va_arg(*ap, unsigned int)));
	else if (c == 'x')
		return (ft_trans_to_x(va_arg(*ap, int)));
	else if (c == 'X')
		return (ft_trans_to_X((va_arg(*ap, int))));
	else if (c == 'p')
		return (ptr_to_str(va_arg(*ap, void *)));
	return (NULL);
}

static char get_conversion_char(char *format, int i)
{
	while (!is_conversion_char(format[++i]))
		;
	return (format[i]);
}

int do_conversion(va_list *ap, char *format, int i)
{
	char conversion_char;
	char *value;

	conversion_char = get_conversion_char(format, i);
	value = get_arg_as_str(ap, conversion_char);
	value = manage_flags(&(format[i]), value, conversion_char);
	ft_putstr(value);
	return (ft_strlen(value));
}
