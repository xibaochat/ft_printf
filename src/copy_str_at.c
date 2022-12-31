/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:22:14 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/23 01:27:38 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	copy_at_the_end(char *value, char **new_value)
{
	int	i;
	int	j;

	i = ft_strlen(value) - 1;
	j = ft_strlen(*new_value) - 1;
	while (i >= 0)
		(*new_value)[j--] = value[i--];
}

void	copy_at_the_begining(char *value, char **new_value)
{
	int	i;

	i = -1;
	while (value && value[++i])
		(*new_value)[i] = value[i];
}

void	ncopy_at_the_begining(unsigned int n, char *value, char **new_value)
{
	int i;

	i = -1;
	while (value && value[++i] && n--)
		(*new_value)[i] = value[i];
}
