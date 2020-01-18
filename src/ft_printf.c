/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:14:40 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/18 09:56:30 by monster_maobe    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	simple_print(char c, int *nb_output, int *i)
{
	ft_putchar(c);
	++(*nb_output);
	++(*i);
}

int			printf_core(va_list *ap, char *format)
{
	int i;
	int nb_output;

	i = 0;
	nb_output = 0;
	while (format[i])
	{
		if (is_conversion(format, &i))
		{
			if (valide_star_nb_combi(format, i) &&
				!has_invalide_char_in_flag(format, i))
			{
				format = manage_star(ap, format, i);
				nb_output += do_conversion(ap, format, i);
				skip_conversion_chars(format, &i);
			}
			else
				simple_print(format[i], &nb_output, &i);
		}
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
