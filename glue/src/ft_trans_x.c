/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:25:59 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/24 03:08:13 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_size(uintmax_t n)
{
	int				size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n > 16)
	{
		size++;
		n = n / 16;
	}
	return (size);
}

static char			*get_converted_str(char *str, uintmax_t res, int *i)
{
	char base[17] = "0123456789abcdef";

	if (res >= 16)
		get_converted_str(str, res / 16, i);
	str[(*i)++] = base[res % 16];
	return (str);
}

char				*ft_trans_to_x(uintmax_t n)
{
	int				i;
	uintmax_t		res;
	char			*str;

	i = 0;
	res = n;
	if (!(str = (char *)malloc(get_size(n) + 1)))
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		res = -1 * n;
	}
	str = get_converted_str(str, res, &i);
	str[i] = '\0';
	return (str);
}
