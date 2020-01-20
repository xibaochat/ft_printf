/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:06:32 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/18 09:13:54 by monster_maobe    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	char_is_n(char c)
{
	return (c == 'x' || c == 'X' || c == 'd' || c == 'i' || c == 'u');
}

static int no_flags_to_apply(t_flag my_flags, char conversion_char)
{
	return (!(my_flags.have_precision) &&
			!(my_flags.f_max_width) &&
			conversion_char != 'p');
}

int no_conversion_char(char c)
{
	return (c == '_');
}

void		manage_flags(char *format, char **value, char conversion_char)
{
	t_flag	my_flags;
	int		v_lens;
	char	*new_value;

	new_value = NULL;
	v_lens = ft_strlen(*value);
	my_flags = ft_initialize_attribution_flag(conversion_char, format);
	tweak_flags_values(&my_flags, *value, conversion_char);
	if (no_flags_to_apply(my_flags, conversion_char))
		return ;
	if (char_is_n(conversion_char) || no_conversion_char(conversion_char))
		new_value = ft_apply_flag_to_nb(my_flags, v_lens, *value);
	else if (conversion_char == 'c')
		new_value = ft_apply_flag_to_char(my_flags, *value);
	else if (conversion_char == 's')
		new_value = ft_apply_flag_to_str(my_flags, *value, v_lens);
	else if (conversion_char == 'p')
		new_value = ft_apply_flag_to_adress(my_flags, *value, v_lens);
	*value = new_value;
}
