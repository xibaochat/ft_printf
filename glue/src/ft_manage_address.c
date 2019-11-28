/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:59:14 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/22 15:40:39 by xinwang          ###   ########.fr       */
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

char	*ft_apply_flag_to_adress(t_flag my_flags, char *value, int v_lens)
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
