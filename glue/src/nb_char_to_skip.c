/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_char_to_skip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:26:51 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/28 16:33:29 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void skip_conversion_chars(char *format, int *i)
{
    while (!is_conversion_char(format[*i]))
		++(*i);
	++(*i);
}
