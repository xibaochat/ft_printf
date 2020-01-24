/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:04:48 by xinwang           #+#    #+#             */
/*   Updated: 2020/01/23 01:20:05 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int			is_signed;
	int			f_max_width;
	int			f_precision;
	int			have_precision;
	int precision_from_zero;
}				t_flag;

int				ft_printf(const char *format, ...);
int				has_invalide_char_in_flag(char *format, int i);
void			ft_putchar(char c);
int				is_conversion(char *format, int *i_format);
void			skip_conversion_chars(char *format, int *i);
int				is_conversion_char(char c);
int				do_conversion(va_list *ap, char *format, int i);
char			*ft_itoa(long int n);
char			*char_to_str(char c);
size_t			ft_strlen(const char *str);
char			*ft_strnew_with_char(int size, char c);
char			*ft_trans_to_x(uintmax_t n);
char			*ft_trans_capital_x(uintmax_t n);
char			*ptr_to_str(void *ptr);
void			manage_flags(char *format, char **value, char conversion_char);
t_flag			ft_initialize_attribution_flag(char conversion_char, char *format);
void			copy_at_the_end(char *value, char **new_value);
void			copy_at_the_begining(char *value, char **new_value);
char			*ft_apply_unsigned_width(t_flag my_flags, char *value);
char			*ft_apply_signed_width(t_flag my_flags, char *value);
char			*ft_apply_signed_width_to_char(t_flag my_flags, char *value);
char			*apply_precision(t_flag *my_flags, char *str);
char			*ft_apply_flag_to_nb(t_flag my_flags, int v_lens, char *value);
char			*ft_apply_flag_to_char(t_flag my_flags, char *value);
char			*ft_apply_flag_to_str(t_flag my_flags, char *value, int v_lens);
char			*apply_precision_on_str(t_flag my_flags, char *value);
void			ncopy_at_the_begining\
				(unsigned int n, char *value, char **new_value);
char			*ft_apply_flag_to_adress\
				(t_flag my_flags, char *value, int v_lens);
int				get_size_int(long int n);
char			*ft_strnew(int size);
char			*replace_star(va_list *ap, char *format, int i);
int				valid_conversion(char *format, int *i_format);
char			*manage_star(va_list *ap, char *format, int i);
int				valide_star_nb_combi(char *format, int i);
char			*ft_strcat(char *dest, char *src);
void			free_str(char **s);
int				is_allowed_char_in_flag(char c);
int				ft_strcmp(const char *s1, const char *s2);
void			add_hex_chars(char **value);
int				is_conversion_char(char c);
void			ft_putstr(char *s);
void			ft_putnbr(int n);
void			ft_put_unsigned_nbr(unsigned int n);
int				char_is_n(char c);
void			tweak_flags_values(t_flag *my_flags, char *value, char conversion_char);
void			print_backslash_zero(char *s);
int				print_value(char **value, int is_backslash_zero);
void			ft_init_precision(t_flag *my_flags, char *format, int *i);
void			ft_init_sign(t_flag *my_flags, char *format, int *i);
int				dot_in_conversion(char *format, int i);
void			ft_init_sign(t_flag *my_flags, char *format, int *i);
int				ft_get_flag_value(char *str, int *i);
char			*ft_strncat(char *dest, char *src, unsigned int nb);

#endif
