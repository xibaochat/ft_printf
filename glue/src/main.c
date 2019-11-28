/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:14:40 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/28 16:37:56 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	ft_printf("bebe chat %.10-59s is cute\n", 420, 42);
	ft_printf("bebe chat %s is cute\n", 420, 42);
	ft_printf("bebe chat %.10s is cute\n", 420, 42);
	ft_printf("bebe chat %-59s is cute\n", 420, 42);
	ft_printf("bebe chat %-59.s is cute\n", 420, 42);
	return (0);
}
