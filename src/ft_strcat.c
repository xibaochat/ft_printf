/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:08:51 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/01 17:08:51 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    *ft_strcat(char *dest, char *src)
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
