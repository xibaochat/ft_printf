/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_value_flag.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:53:34 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/20 17:38:17 by monster_maobe    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void skip_zeroes_and_minus(char *s, int *i)
{
	while (s[*i] && (s[*i] == '-' || s[*i] == '0'))
		++(*i);
}

static int	ft_get_flag_value(char *str, int *i)
{
	int	s;

	s = 0;
	skip_zeroes_and_minus(str, i);
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		s = s * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (s);
}

static void	ft_init_sign(t_flag *my_flags, char *format, int *i)
{
	int mem;

	mem = *i;
	while (format[*i] && format[*i] == '0')
		(*i)++;
	while (format[*i] && format[*i] == '-')
	{
		(*my_flags).is_signed = 1;
		(*i)++;
	}
	if (!(*my_flags).is_signed)
		*i = mem;
	if (*i == 0)
		(*my_flags).is_signed = 0;
}

static void	ft_init_precision(t_flag *my_flags, char *format, int *i)
{
	int have_precision;

	have_precision = 0;
	if (format[*i] == '.')
	{
		(*i)++;
		++have_precision;
	}
	if (have_precision || (format[*i] >= '0' && format[*i] <= '9'))
	{
		my_flags->f_precision = ft_get_flag_value(format, i);
		my_flags->have_precision = 1;
	}
	else
	{
		my_flags->f_precision = 0;
		my_flags->have_precision = 0;
	}
}

int dot_in_conversion(char *format, int i)
{
	while (!is_conversion_char(format[i]))
	{
		if (format[i] == '.')
			return (1);
		++i;
	}
	return (0);
}

int not_zero_width(char *format, int i)
{
	while (format[++i] == '0')
		;
	if (format[i] > '0' && format[i] <= '9')
		return (1);
	return (0);
}

int valid_precision_from_zero_cchar(char c)
{
	if (char_is_n(c) || c == 's' || c == '_')
		return (1);
	return (0);
}

int ft_get_width(t_flag *my_flags, char *format, int *i, char conversion_char)
{
	if (valid_precision_from_zero_cchar(conversion_char) &&
		!dot_in_conversion(format, *i) &&
		format[*i] == '0' && !(my_flags->is_signed) &&
		not_zero_width(format, *i))
	{
		while (format[*i + 1] && format[*i + 1] == '0')
			(*i)++;
		format[*i] = '.';
		my_flags->precision_from_zero = 1;
		return (0);
	}
	return ft_get_flag_value(format, i);
}

void init_my_flags(t_flag *my_flags)
{
	my_flags->is_signed = 0;
	my_flags->f_max_width = 0;
	my_flags->f_precision = 0;
	my_flags->have_precision = 0;
	my_flags->precision_from_zero = 0;
}

t_flag		ft_initialize_attribution_flag(char conversion_char, char *format)
{
	int		i;
	t_flag	my_flags;

	i = 0;
	init_my_flags(&my_flags);
	ft_init_sign(&my_flags, format, &i);
	my_flags.f_max_width = ft_get_width(&my_flags, format, &i, conversion_char);
	ft_init_precision(&my_flags, format, &i);
	return (my_flags);
}
