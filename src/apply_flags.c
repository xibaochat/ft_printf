/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:06:58 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/18 10:56:50 by monster_maobe    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	replace_str_by(char **dest, char *src)
{
	free_str(dest);
	*dest = src;
}

char	*ft_apply_flag_to_adress(t_flag my_flags, char *value, int v_lens)
{
	if (my_flags.f_precision > v_lens)
		replace_str_by(&value, apply_precision(&my_flags, value));
	else if (!(my_flags.f_precision))
		replace_str_by(&value, ft_strnew(1));
	add_hex_chars(&value);
	if ((unsigned int)my_flags.f_max_width > ft_strlen(value))
	{
		if (my_flags.is_signed)
			replace_str_by(&value, ft_apply_signed_width(my_flags, value));
		else
			replace_str_by(&value, ft_apply_unsigned_width(my_flags, value));
	}
	return (value);
}

char	*ft_apply_flag_to_nb(t_flag my_flags, int v_lens, char *value)
{
	if (my_flags.f_precision > v_lens)
		replace_str_by(&value, apply_precision(&my_flags, value));
	else if (my_flags.have_precision &&
			my_flags.f_precision == 0 &&
			!ft_strcmp(value, "0"))
		replace_str_by(&value, ft_strnew(1));
	if ((unsigned int)my_flags.f_max_width > ft_strlen(value) &&
		my_flags.is_signed)
		replace_str_by(&value, ft_apply_signed_width(my_flags, value));
	else if ((unsigned int)my_flags.f_max_width > ft_strlen(value) &&
		!my_flags.is_signed)
		replace_str_by(&value, ft_apply_unsigned_width(my_flags, value));
	return (value);
}

char	*ft_apply_flag_to_char(t_flag my_flags, char *value)
{
	if (my_flags.f_max_width > 1 && my_flags.is_signed)
		replace_str_by(&value, ft_apply_signed_width_to_char(my_flags, value));
	else if (my_flags.f_max_width > 1 && !my_flags.is_signed)
		replace_str_by(&value, ft_apply_unsigned_width(my_flags, value));
	return (value);
}

char	*ft_apply_flag_to_str(t_flag my_flags, char *value, int v_lens)
{
	if (my_flags.have_precision && my_flags.f_precision < v_lens)
		replace_str_by(&value, apply_precision_on_str(my_flags, value));
	else if (my_flags.precision_from_zero)
		replace_str_by(&value, apply_precision(&my_flags, value));
	if ((unsigned int)my_flags.f_max_width > ft_strlen(value))
	{
		if (my_flags.is_signed)
			replace_str_by(&value, ft_apply_signed_width(my_flags, value));
		else
			replace_str_by(&value, ft_apply_unsigned_width(my_flags, value));
	}
	return (value);
}
