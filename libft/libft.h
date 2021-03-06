/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:04:48 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/21 01:27:31 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);
size_t				ft_strlen(const char *str);
void			    ft_put_unsigned_nbr(unsigned int n);
char                *ft_trans_to_x(uintmax_t n);
char                *ft_trans_to_X(uintmax_t n);
char				*ft_ptr(void *ptr);
size_t				ft_strlen(const char *str);
char    			*ft_strnew_with_zero(int size);
char    			*ft_strnew_with_space(int size);

#endif
