/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:14:40 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/28 16:36:38 by dh4rm4           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int do_job(va_list *ap, char *format)
{
	int	i;
	int nb_output;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && is_conversion(format, &i))
		{
//			nb_output = do_conversion(format, i);
			skip_conversion_chars(format, &i);
			ft_putchar('X');
		}
		else
		{
			ft_putchar(format[i]);
			++nb_output;
			++i;
		}
	}
	return (nb_output);
}

int ft_printf(char *format, ...)
{
	va_list	ap;

	if (!format)
		return (0);
	va_start(ap, format);
	return (do_job(&ap, format));
}
