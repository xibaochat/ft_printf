/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:14:40 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/23 01:32:44 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	simple_print(char c, int *nb_output, int *i)
{
	ft_putchar(c);
	++(*nb_output);
	++(*i);
}

static void	manage_conversion(va_list *ap, char **format, int *i, int *nb_out)
{
	if (valide_star_nb_combi(*format, *i) &&
		!has_invalide_char_in_flag(*format, *i))
	{
		*format = manage_star(ap, *format, *i);
		*nb_out += do_conversion(ap, *format, *i);
		skip_conversion_chars(*format, i);
	}
	else if ((*format)[*i] && (*format)[*i + 1] && (*format)[*i + 1] == '%')
		simple_print((*format)[*i], nb_out, i);
	else
		++(*i);
}

int			printf_core(va_list *ap, char *format)
{
	int	i;
	int	nb_output;

	i = 0;
	nb_output = 0;
	while (format[i])
	{
		if (is_conversion(format, &i))
			manage_conversion(ap, &format, &i, &nb_output);
		else
			simple_print(format[i], &nb_output, &i);
	}
	free_str(&format);
	return (nb_output);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*new_format;

	if (!format)
		return (0);
	va_start(ap, format);
	new_format = ft_strnew(ft_strlen(format) + 1);
	ft_strcat(new_format, (char *)format);
	return (printf_core(&ap, new_format));
}
