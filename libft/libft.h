/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:04:48 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/22 14:32:49 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>


typedef struct s_flaf
{
	int         is_signed;
	int         f_max_width;
	int         f_precision;
	int			have_precision;
}               t_flag;

void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);
size_t				ft_strlen(const char *str);
void			    ft_put_unsigned_nbr(unsigned int n);
char                *ft_trans_to_x(uintmax_t n);
char                *ft_trans_to_X(uintmax_t n);
char				*ft_ptr(void *ptr);
size_t				ft_strlen(const char *str);
char    			*ft_strnew_with_char(int size, char c);
void				copy_at_the_end(char *value, char **new_value);
void				copy_at_the_begining(char *value, char **new_value);
int					ft_get_flag_value(char *str, int *i);
void				ft_init_sign(t_flag *my_flags, char *format, int *i);
void				ft_init_precision(t_flag *my_flags, char *format, int *i);
t_flag				ft_initialize_attribution_flag(char *format);
char				*ft_apply_unsigned_width(t_flag my_flags, char *value);
char				*ft_apply_signed_width(t_flag my_flags, char *value);
char				*ft_apply_signed_width(t_flag my_flags, char *value);
char				*ft_apply_precision(int v_precision, char *str);
char *ft_apply_flag_to_nb(t_flag my_flags, int v_lens, char *value);
char *ft_apply_flag_to_char(t_flag my_flags, char *value);
char *ft_apply_precision_on_str(t_flag my_flags, char *value);
void ncopy_at_the_begining(unsigned int n, char *value, char **new_value);
char    *ft_apply_flag_to_adress(t_flag my_flags, char *value, int v_lens);
// TESTS
void test_str_width(void);
void test_str_precision(void);
void test_str_precision_with_width(void);

void test_nb_width(void);
void test_nb_precision(void);
void test_nb_precision_with_width(void);

void test_ptr_width(void);
void test_ptr_precision(void);
void test_ptr_precision_with_width(void);

#endif
