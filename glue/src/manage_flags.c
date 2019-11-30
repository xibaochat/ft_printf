/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:06:32 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/30 00:39:46 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int char_is_n(char c)
{
	return (c == 'x' || c == 'X' || c == 'd' || c == 'i' || c == 'u');
}

char *manage_flags(char *format, char *value, char conversion_char)
{
	t_flag my_flags;
	int v_lens;

	v_lens = ft_strlen(value);
	my_flags = ft_initialize_attribution_flag(format);
	if (!(my_flags.have_precision) && !(my_flags.f_max_width))
		return (value);
	if (char_is_n(conversion_char))
		return (ft_apply_flag_to_nb(my_flags, v_lens, value));
	else if (conversion_char == 'c')
		return (ft_apply_flag_to_char(my_flags, value));
	else if (conversion_char == 's')
		return (ft_apply_flag_to_str(my_flags, value, v_lens));
	else if (conversion_char == 'p')
		return (ft_apply_flag_to_adress(my_flags, value, v_lens));
}
