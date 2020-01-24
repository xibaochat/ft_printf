/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 01:19:21 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/23 01:34:25 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int	lens;
    unsigned int    i;

    i = 0;
    lens = ft_strlen(dest);
    while (src[i] && i < nb)
        dest[lens++] = src[i++];
    dest[lens] = '\0';
    return (dest);
}
