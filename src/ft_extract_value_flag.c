/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_value_flag.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:53:34 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/23 00:22:52 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void skip_zeroes_and_minus(char *s, int *i)
{
	while (s[*i] && (s[*i] == '-' || s[*i] == '0'))
		++(*i);
}

int	ft_get_flag_value(char *str, int *i)
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

void	ft_init_sign(t_flag *my_flags, char *format, int *i)
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
}

void	ft_init_precision(t_flag *my_flags, char *format, int *i)
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
