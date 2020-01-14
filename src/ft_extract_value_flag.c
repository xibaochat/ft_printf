/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_value_flag.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:53:34 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/14 12:58:30 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	has_point(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_get_flag_value(t_flag *my_flags, char conversion_char, char *str, int *i)
{
	int	s;

	s = 0;
	if (conversion_char != 's' && str[*i] && str[*i] == '0')
	{
		while (str[*i] && str[*i] == '0')
			(*i)++;
		if (char_is_n(conversion_char))
			my_flags->have_precision = 1;
		if (!has_point(str, *i) || my_flags->have_precision)
			return (0);
	}
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
	while (format[*i] == '0')
		(*i)++;
	if (have_precision || (format[*i] >= '0' && format[*i] <= '9'))
	{
		my_flags->f_precision = ft_get_flag_value(my_flags, '\0', format, i);
		my_flags->have_precision = 1;
	}
	else
	{
		my_flags->f_precision = 0;
		my_flags->have_precision = 0;
	}
}

t_flag		ft_initialize_attribution_flag(char conversion_char, char *format)
{
	int		i;
	t_flag	my_flags;

	i = 0;
	ft_init_sign(&my_flags, format, &i);
	my_flags.f_max_width = ft_get_flag_value(&my_flags, conversion_char, format, &i);
	ft_init_precision(&my_flags, format, &i);
	return (my_flags);
}
