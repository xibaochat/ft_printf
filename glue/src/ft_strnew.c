/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 04:47:54 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/29 15:59:51 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_with_char(int size, char c)
{
	char *ptr;
	int  i;

	if (!(ptr = (char *)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = c;
	ptr[i] = '\0';
	return (ptr);
}

char    *ft_strnew(int size)
{
	char *ptr;
	int  i;

	if (!(ptr = (char *)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = 0;
	return (ptr);
}
