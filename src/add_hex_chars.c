/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hex_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 03:12:31 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/04 03:12:51 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void add_hex_chars(char **value)
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
