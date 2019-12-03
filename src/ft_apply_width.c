/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_unsigned_width.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:23:29 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/03 22:02:29 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_apply_unsigned_width(t_flag my_flags, char *value)
{
	char *new_value;

	new_value = ft_strnew_with_char(my_flags.f_max_width, ' ');
	if (new_value)
	{
		copy_at_the_end(value, &new_value);
		return (new_value);
	}
	return (NULL);
}

char *ft_apply_signed_width_to_char(t_flag my_flags, char *value)
{
	if (ESCAPED_ZERO_CHAR_CONVERSION)
		--(my_flags.f_max_width);
	return (ft_apply_signed_width(my_flags, value));
}

char *ft_apply_signed_width(t_flag my_flags, char *value)
{
	char *new_value;

	new_value = ft_strnew_with_char(my_flags.f_max_width, ' ');
	if (new_value)
	{
		copy_at_the_begining(value, &new_value);
		return (new_value);
	}
	return (NULL);
}
