/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:06:32 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/03 22:22:30 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int char_is_n(char c)
{
	return (c == 'x' || c == 'X' || c == 'd' || c == 'i' || c == 'u');
}

void manage_flags(char *format, char **value, char conversion_char)
{
	t_flag my_flags;
	int v_lens;
	char *new_value;

	new_value = NULL;
	v_lens = ft_strlen(*value);
	my_flags = ft_initialize_attribution_flag(format);
	if (!(my_flags.have_precision) && !(my_flags.f_max_width) && conversion_char != 'p')
		return ;
	if (char_is_n(conversion_char))
		new_value = ft_apply_flag_to_nb(my_flags, v_lens, *value);
	else if (conversion_char == 'c')
		new_value = ft_apply_flag_to_char(my_flags, *value);
	else if (conversion_char == 's')
		new_value = ft_apply_flag_to_str(my_flags, *value, v_lens);
	else if (conversion_char == 'p')
		new_value = ft_apply_flag_to_adress(my_flags, *value, v_lens);
	*value = new_value;
}
