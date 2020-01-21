/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:12:43 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/05 14:26:43 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	lens;
	unsigned int	i;

	i = 0;
	lens = ft_strlen(dest);
	while (src[i] && i < nb)
		dest[lens++] = src[i++];
	dest[lens] = '\0';
	return (dest);
}

char			*replace_star(va_list *ap, char *format, int i)
{
	char		*new_str;
	char		*s_value;
	int			value;

	s_value = NULL;
	value = va_arg(*ap, int);
	new_str = ft_strnew(ft_strlen(format) + get_size_int(value));
	new_str = ft_strncat(new_str, format, i);
	s_value = ft_itoa(value);
	ft_strcat(new_str + i, s_value);
	ft_strcat(new_str + (i + ft_strlen(s_value)), format + i + 1);
	free_str(&s_value);
	free_str(&format);
	return (new_str);
}

char * remove_current_start(char *format, int i)
{
	char *new_str;

	new_str = ft_strnew(ft_strlen(format));
	ft_strncat(new_str, format, i);
	ft_strncat(new_str, format + i + 2, ft_strlen(format) - i - 1);
	free_str(&format);
	return (new_str);
}


char			*manage_precision_star(va_list *ap, char *format, int i)
{
	char		*new_str;
	char		*s_value;
	int			value;

	s_value = NULL;
	value = va_arg(*ap, int);
	if (value < 0)
		return remove_current_start(format, i);
	i++;
	new_str = ft_strnew(ft_strlen(format) + get_size_int(value));
	new_str = ft_strncat(new_str, format, i);

	s_value = ft_itoa(value);

	ft_strcat(new_str + i, s_value);
	ft_strcat(new_str + (i + ft_strlen(s_value)), format + i + 1);

	free_str(&s_value);
	free_str(&format);
	return (new_str);
}


int precision_star(char *format, int i)
{
	return (format[i] == '.' && format[i + 1] && format[i + 1] == '*');
}


char			*manage_star(va_list *ap, char *format, int i)
{
	while (format[i] && format[i] != '*' &&
		   !is_conversion_char(format[i]) && format[i] != '.')
		i++;
	if (!format[i] || is_conversion_char(format[i]))
		return (format);
	if (format[i] != '.')
		format = replace_star(ap, format, i);
	while (format[i] && format[i] != '.' && !is_conversion_char(format[i]))
		i++;
	if (precision_star(format, i))
		format = manage_precision_star(ap, format, i);
	return (format);
}
