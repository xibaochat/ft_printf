/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:14:40 by xinwang           #+#    #+#             */
/*   Updated: 2019/12/01 18:27:29 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int main(void)
{
	char s[5] = "BOID";

//	ft_printf("bebe chat %.10-59s ip cute\n", s, 42);
//	ft_printf("bebe chat %s in cute\n", s, 42);
//  ft_printf("bebe chat %.10s ip cute\n", s, 42);
//	ft_printf("bebe chat %-59s ip cute\n", s, 42);
	//ft_printf("bebe chat %s ip cute\n", 10, s);
//	ft_printf("bebe chat %*****s ip cute\n", 10, s);

//	ft_printf("%-10d\n", 10, 49);
//	printf("%-10d\n", 10, 49);
//	ft_printf("%*d\n", 10, 49);
//	printf("%*d\n", 10, 49);
//	ft_printf("%*.*d\n", 10, 0, 49);
//	printf("%*.*d\n", 10, 0, 49);
//	ft_printf("%.*d\n", 10, 49);
//	printf("%.*d\n", 10, 49);
//	ft_printf("%10.*d\n", 10, 49);
//	printf("%10.*d\n", 10, 49);
//	ft_printf("%-10.*d\n", 10, 49);
//	printf("%-10.*d\n", 10, 49);
//	ft_printf("bebe chat hen lei %*.*s kitten\n", 10, 15, "420");
//	printf("bebe chat hen lei %*.*s kitten\n", 10, 15, "420");


//	printf("bebe chat %*.7s ip cute\n", 10,  s);
//	ft_printf("bebe chat %*.7s ip cute\n", 10, s);
	ft_printf("%u\n", 2147483648);
	printf("%u\n", 2147483648);
//	printf("bebe chat %-59.s ip cute\n", s, 42);
	return (0);
}



/*
1. multiple '*' in width &&/|| precision
2. mutiple precison
3. mutiple width
4. precision before width
5. Not managed conversion (not s, x, c, ...)
6. Anything else than [number, *, ., -] before conversion char is invalid
*/
