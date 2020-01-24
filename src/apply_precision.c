/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:22:14 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/23 01:26:34 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*apply_precision_on_neg(t_flag *my_flags, char *str)
{
	char	*new_str;
	int from_zero;
	int f_precision;

	from_zero = my_flags->precision_from_zero;
	f_precision = my_flags->f_precision;
	if (from_zero)
		new_str = ft_strnew_with_char(f_precision, '0');
	else
		new_str = ft_strnew_with_char(f_precision + 1, '0');
	if (new_str)
	{
		new_str[0] = '-';
		copy_at_the_end(str + 1, &new_str);
		return (new_str);
	}
	return (NULL);
}

char		*apply_precision(t_flag *my_flags, char *str)
{
	char	*new_str;

	if (str && str[0] == '-')
		return (apply_precision_on_neg(my_flags, str));
	new_str = ft_strnew_with_char(my_flags->f_precision, '0');
	if (new_str)
	{
		copy_at_the_end(str, &new_str);
		return (new_str);
	}
	return (NULL);
}

char		*apply_precision_on_str(t_flag my_flags, char *value)
{
	char	*new_value;

	new_value = ft_strnew_with_char(my_flags.f_precision, ' ');
	ncopy_at_the_begining(my_flags.f_precision, value, &new_value);
	return (new_value);
}
