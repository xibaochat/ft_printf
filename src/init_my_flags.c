/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_my_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:46:09 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/14 15:48:28 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void init_my_flags(t_flag *my_flags)
{
	my_flags->is_signed = 0;
	my_flags->f_max_width = 0;
	my_flags->f_precision = 0;
	my_flags->have_precision = 0;
	my_flags->precision_from_zero = 0;
}
