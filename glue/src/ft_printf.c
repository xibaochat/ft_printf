/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:14:40 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/29 19:12:51 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void simple_print(char c, int *nb_output, int *i)
{
	ft_putchar(c);
	++(*nb_output);
	++(*i);
}

int printf_core(va_list *ap, char *format)
{
	int	i;
	int nb_output;

	i = 0;
	nb_output = 0;
	while (format[i])
	{
		if (is_conversion(format, &i))
		{
			format = replace_star(ap, format);
			if (valid_conversion(format, &i))
			{
				nb_output += do_conversion(ap, format, i);
				skip_conversion_chars(format, &i);
			}
			else
				simple_print(format[i], &nb_output, &i);
		}
		else
			simple_print(format[i], &nb_output, &i);
	}
	return (nb_output);
}

int ft_printf(char *format, ...)
{
	va_list	ap;

	if (!format)
		return (0);
	va_start(ap, format);
	return (printf_core(&ap, format));
}
