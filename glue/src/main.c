/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:14:40 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/28 18:27:56 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	char s[5] = "BOID";

//	ft_printf("bebe chat %.10-59s ip cute\n", s, 42);
//	ft_printf("bebe chat %s in cute\n", s, 42);
//  ft_printf("bebe chat %.10s ip cute\n", s, 42);
//	ft_printf("bebe chat %-59s ip cute\n", s, 42);
	ft_printf("bebe chat %-59.s ip cute\n", s, 42);
	printf("bebe chat %-59.s ip cute\n", s, 42);
	return (0);
}
