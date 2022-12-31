/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:36:57 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/23 01:28:12 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*get_str_from_arg(va_list *ap)
{
	char	*arg;
	char	*new;

	arg = va_arg(*ap, char *);
	new = NULL;
	if (arg)
	{
		new = ft_strnew(ft_strlen(arg) + 1);
		ft_strcat(new, arg);
	}
	else
	{
		new = ft_strnew(7);
		ft_strcat(new, "(null)");
	}
	return (new);
}

static char	*get_arg_as_str(va_list *ap, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(*ap, int)));
	else if (c == 's')
		return (get_str_from_arg(ap));
	else if (c == 'c')
		return (char_to_str(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_itoa(va_arg(*ap, unsigned int)));
	else if (c == 'x')
		return (ft_trans_to_x(va_arg(*ap, unsigned int)));
	else if (c == 'X')
		return (ft_trans_capital_x((va_arg(*ap, unsigned int))));
	else if (c == 'p')
		return (ptr_to_str(va_arg(*ap, void *)));
	else if (c == '_')
		return (ft_strnew_with_char(1, '%'));
	return (NULL);
}

static char	get_conversion_char(char *format, int i)
{
	while (format[i] && !is_conversion_char(format[i]) && format[i] != '%')
		++i;
	if (format[i] == '%')
		return ('_');
	return (format[i]);
}

int			do_conversion(va_list *ap, char *format, int i)
{
	char	conversion_char;
	char	*value;
	int		is_backslash_zero;

	value = NULL;
	is_backslash_zero = 0;
	conversion_char = get_conversion_char(format, i);
	value = get_arg_as_str(ap, conversion_char);
	if (conversion_char == 'c' && value && !value[0])
	{
		++is_backslash_zero;
		value[0] = '_';
	}
	manage_flags(&(format[i]), &value, conversion_char);
	return (print_value(&value, is_backslash_zero));
}
