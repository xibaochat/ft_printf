 #include <stdio.h>
#include "libft.h"

int char_is_n(char c)
{
	return (c == 'x' || c == 'X' || c == 'd' || c == 'i' || c == 'u');
}

char *ft_apply_flag_to_nb(t_flag my_flags, int v_lens, char *value)
{
	if (my_flags.f_precision > v_lens)
		value = ft_apply_precision(my_flags.f_precision, value);
	if (my_flags.f_max_width > ft_strlen(value) && my_flags.is_signed)
		value = ft_apply_signed_width(my_flags, value);
	else if (my_flags.f_max_width > ft_strlen(value) && !my_flags.is_signed)
		value = ft_apply_unsigned_width(my_flags, value);
	return (value);
}

char *ft_apply_flag_to_char(t_flag my_flags, char *value)
{
	if (my_flags.f_max_width > 1 && my_flags.is_signed)
		value = ft_apply_signed_width(my_flags, value);
	else if (my_flags.f_max_width > 1 && !my_flags.is_signed)
		value = ft_apply_unsigned_width(my_flags, value);
	return (value);
}

char *ft_apply_flag_to_str(t_flag my_flags, char *value, int v_lens)
{
	if (my_flags.have_precision && my_flags.f_precision < v_lens)
		value = ft_apply_precision_on_str(my_flags, value);
	if (my_flags.f_max_width > ft_strlen(value))
	{
		if (my_flags.is_signed)
			value = ft_apply_signed_width(my_flags, value);
		else
			value = ft_apply_unsigned_width(my_flags, value);
	}
	return (value);
}

char *ft_manage_flags(char *format, char *value, char c)
{
	t_flag my_flags;
	int v_lens;

	v_lens = ft_strlen(value);
	my_flags = ft_initialize_attribution_flag(format);
	if (char_is_n(c))
		return(ft_apply_flag_to_nb(my_flags, v_lens, value));
	else if (c == 'c')
		return (ft_apply_flag_to_char(my_flags, value));
	else if (c == 's')
		return (ft_apply_flag_to_str(my_flags, value, v_lens));
	else if (c == 'p')
		return (ft_apply_flag_to_adress(my_flags, value, v_lens));
}

int main()
{
/*	test_str_width();
	test_str_precision();
	test_str_precision_with_width();

	test_nb_width();
	test_nb_precision();
	test_nb_precision_with_width();
*/
	test_ptr_width();
	test_ptr_precision();
	test_ptr_precision_with_width();





	return (0);
}
