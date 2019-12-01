/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_value_flag.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:53:34 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/30 01:02:15 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int ft_get_flag_value(char *str, int *i)
{
	int s;

	s = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		s = s * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (s);
}

static void ft_init_sign(t_flag *my_flags, char *format, int *i)
{
	while (format[*i] && format[*i] == '-')
	{
		(*my_flags).is_signed = 1;
		(*i)++;
	}
	if (*i == 0)
		(*my_flags).is_signed = 0;
}

static void ft_init_precision(t_flag *my_flags, char *format, int *i)
{
	if (format[*i] == '.')
	{
		(*i)++;
		my_flags->f_precision = ft_get_flag_value(format, i);
		my_flags->have_precision = 1;
	}
	else
	{
		my_flags->f_precision = 0;
		my_flags->have_precision = 0;
	}
}

t_flag	ft_initialize_attribution_flag(char *format)
{
	int i;
	t_flag my_flags;

	i = 0;
	ft_init_sign(&my_flags, format, &i);
	my_flags.f_max_width = ft_get_flag_value(format, &i);
	ft_init_precision(&my_flags, format, &i);
	return my_flags;
}
