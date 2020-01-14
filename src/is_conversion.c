/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:03:30 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/14 13:19:58 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			is_allowed_char_in_flag(char c)
{
	return ((c >= '0' && c <= '9') || c == '*' || c == '.' ||
			c == '-');
}

static int	has_nb_and_star(char *format, int *i)
{
	int mark;

	mark = 0;
	while (format[*i] && format[*i] == '-')
		(*i)++;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		(*i)++;
		mark = 1;
	}
	while (format[*i] && format[*i] == '-')
		(*i)++;
	if (format[*i] == '*' && mark)
		return (1);
	return (0);
}

static	int	nb_stars(char *format, int *i)
{
	int nb_stars;

	nb_stars = 0;
	while (format[*i] && format[*i] == '*')
	{
		nb_stars++;
		(*i)++;
	}
	return (nb_stars);
}

int			valide_star_nb_combi(char *format, int i)
{
	if (has_nb_and_star(format, &i))
		return (0);
	if (nb_stars(format, &i) > 1)
		return (0);
	if (format[i] == '.')
		i++;
	if (nb_stars(format, &i) > 1)
		return (0);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (!is_conversion_char(format[i]))
		return (0);
	return (1);
}

int			is_conversion(char *format, int *i)
{
	int j;

	j = *i;
	if (format[j] != '%' || !format[j + 1])
		return (0);
	(*i)++;
	if (invalid_percent_char(format, *i))
		return (skip_invalid_percent_chars(format, i));
	return (1);
}
