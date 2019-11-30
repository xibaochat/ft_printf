/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:06:58 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/30 00:41:07 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void add_hex_chars(char **value)
{
	char *new;

	new = ft_strnew_with_char(ft_strlen(*value) + 2, '_');
	copy_at_the_end(*value, &new);
	if (*value)
		free(*value);
	*value = new;
	(*value)[0] = '0';
	(*value)[1] = 'x';
}

char *ft_apply_flag_to_adress(t_flag my_flags, char *value, int v_lens)
{

	if (my_flags.f_precision > v_lens)
		value = ft_apply_precision(my_flags.f_precision, value);
	add_hex_chars(&value);
	if (my_flags.f_max_width > ft_strlen(value))
	{
		if (my_flags.is_signed)
			value = ft_apply_signed_width(my_flags, value);
		else
			value = ft_apply_unsigned_width(my_flags, value);
	}
	return (value);
}

char *ft_apply_flag_to_nb(t_flag my_flags, int v_lens, char *value)
{
	if (my_flags.f_precision > v_lens)
		value = ft_apply_precision(my_flags.f_precision, value);
	if (my_flags.f_max_width > ft_strlen(value) && my_flags.is_signed)
		value = ft_apply_signed_width(my_flags, value);
	else if (my_flags.f_max_width > ft_strlen(value) && !my_flags.is_signed)
		value = ft_apply_unsigned_width(my_flags, value);
	return (value);
}

char *ft_apply_flag_to_char(t_flag my_flags, char *value)
{
	if (my_flags.f_max_width > 1 && my_flags.is_signed)
		value = ft_apply_signed_width(my_flags, value);
	else if (my_flags.f_max_width > 1 && !my_flags.is_signed)
		value = ft_apply_unsigned_width(my_flags, value);
	return (value);
}

char *ft_apply_flag_to_str(t_flag my_flags, char *value, int v_lens)
{
	if (my_flags.have_precision && my_flags.f_precision < v_lens)
		value = ft_apply_precision_on_str(my_flags, value);
	if (my_flags.f_max_width > ft_strlen(value))
	{
		if (my_flags.is_signed)
			value = ft_apply_signed_width(my_flags, value);
		else
			value = ft_apply_unsigned_width(my_flags, value);
	}
	return (value);
}
