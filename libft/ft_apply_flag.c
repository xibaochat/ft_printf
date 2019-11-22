/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:57:15 by xinwang           #+#    #+#             */
/*   Unpdated: 2019/11/21 22:02:26 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char *ft_apply_precision(int v_precision, char *str)
{
	char *new_str;

	new_str = ft_strnew_with_char(v_precision, '0');
	if (new_str)
	{
		copy_at_the_end(str, &new_str);
		return (new_str);
	}
	return (NULL);
}

char *ft_apply_precision_on_str(t_flag my_flags, char *value)
{
	char *new_value;

	new_value = ft_strnew_with_char(my_flags.f_precision, ' ');
	if (new_value)
	{
		ncopy_at_the_begining(my_flags.f_precision, value, &new_value);
		return (new_value);
	}
	return (NULL);
}
