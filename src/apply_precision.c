/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:22:14 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/04 03:40:34 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*apply_precision_on_neg(int v_precision, char *str)
{
	char	*new_str;

	new_str = ft_strnew_with_char(v_precision + 1, '0');
	new_str[0] = '-';
	if (new_str)
	{
		copy_at_the_end(str + 1, &new_str);
		return (new_str);
	}
	return (NULL);
}

char		*apply_precision(int v_precision, char *str)
{
	char	*new_str;

	if (str && str[0] == '-')
		return (apply_precision_on_neg(v_precision, str));
	new_str = ft_strnew_with_char(v_precision, '0');
	if (new_str)
	{
		copy_at_the_end(str, &new_str);
		return (new_str);
	}
	return (NULL);
}

char		*apply_precision_on_str(t_flag my_flags, char *value)
{
	char *new_value;

	new_value = ft_strnew_with_char(my_flags.f_precision, ' ');
	if (!ft_strcmp(value, "(null)"))
	{
		free_str(&value);
		value = ft_strnew(1);
	}
	else if (new_value)
	{
		ncopy_at_the_begining(my_flags.f_precision, value, &new_value);
		return (new_value);
	}
	return (NULL);
}
