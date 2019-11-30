
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:12:43 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/30 06:01:05 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char    *ft_strcat(char *dest, char *src)
{
	unsigned int    lens;
	unsigned int    i;

	i = 0;
	lens = ft_strlen(dest);
	while (src[i])
		dest[lens++] = src[i++];
	dest[lens] = '\0';
	return (dest);
}

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
	int value;

	value = va_arg(*ap, int);
	new_str = ft_strnew(ft_strlen(format) + get_size_int(value));
	new_str = ft_strncat(new_str, format, i);
	ft_strcat(new_str + i, ft_itoa(value));
	ft_strcat(new_str + (i + get_size_int(value)), format + i + 1);

	return (new_str);
}

char *manage_star(va_list *ap, char *format, int i)
{
	int j;
	int k;

	j = 0;
	while (format[i] && format[i] != '*')
		i++;
	if (format[i] == '*')
		format = replace_star(ap, format, i);
	k = i;
	while (format[k] && format[k] == '*')
	{
		j++;
		k++;
	}
	while (format[i] && format[i] != '.')
		i++;
	if (format[i] == '.' && format[++i] == '*' && j < 2)
		format = replace_star(ap, format, i);
	return (format);
}
