
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:12:43 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/01 20:13:41 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char    *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int    lens;
	unsigned int    i;

	i = 0;
	lens = ft_strlen(dest);
	while (src[i] && i < nb)
		dest[lens++] = src[i++];
	dest[lens] = '\0';
	return (dest);
}

char *replace_star(va_list *ap, char *format, int i)
{
	char *new_str;
	char *s_value;
	int value;

	s_value = NULL;
	value = va_arg(*ap, int);
	new_str = ft_strnew(ft_strlen(format) + get_size_int(value));
	new_str = ft_strncat(new_str, format, i);

	s_value = ft_itoa(value);
	ft_strcat(new_str + i, s_value);
	ft_strcat(new_str + (i + get_size_int(value)), format + i + 1);
	free_str(&s_value);
	return (new_str);
}

char *manage_star(va_list *ap, char *format, int i)
{
	int j;
	int k;
	char *tmp;

	j = 0;
	while (format[i] && format[i] != '*')
		i++;
	if (format[i] == '*')
	{
		tmp = replace_star(ap, format, i);
		free_str(&format);
		format = tmp;
	}
	k = i;
	while (format[k] && format[k] == '*')
	{
		j++;
		k++;
	}
	while (format[i] && format[i] != '.')
		i++;
	if (format[i] == '.' && format[++i] == '*' && j < 2)
	{
		tmp = replace_star(ap, format, i);
		free_str(&format);
		format = tmp;
	}
	return (format);
}
