/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tweak_flags_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:04:48 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/23 01:20:05 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	special_case_one(t_flag *my_flags, char *value, char c)
{
	return (c == 's' &&
			my_flags->precision_from_zero &&
			(size_t)my_flags->f_precision < ft_strlen(value));
}

void		tweak_flags_values(t_flag *my_flags, char *value, char c)
{
	if (special_case_one(my_flags, value, c))
	{
		my_flags->precision_from_zero = 0;
		my_flags->have_precision = 0;
		my_flags->f_max_width = my_flags->f_precision;
		my_flags->f_precision = 0;
	}
}
