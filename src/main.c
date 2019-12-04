/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:14:40 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/04 01:36:49 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int main(void)
{
	char s = 'B';
//	printf("bebe chat %*.7s ip cute\n", 10,  s);
//	ft_printf("bebe chat %*.7s ip cute\n", 10, s);


	ft_printf("|%05.1d|\n", 0);
	printf("|%05.1d|\n", 0);

	ft_printf("|%05.1x|\n", 0);
	printf("|%05.1x|\n", 0);

	ft_printf("|%05.1u|\n", 0);
	printf("|%05.1u|\n", 0);

	ft_printf("|%05.1s|\n", "boid");
	printf("|%05.1s|\n", "boid");

	ft_printf("|%05.1p|\n", s);
	printf("|%05.1p|\n", s);
}
