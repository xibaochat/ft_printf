#include "libftprintf.h"

/*
  Special cases:
  #1 (e.g. %03s) where the given string is lower than the precision.
     |-> we consider the flag as width, not precision.
*/

static int special_case_one(t_flag *my_flags, char *value, char conversion_char)
{
    return (conversion_char == 's' &&
			my_flags->precision_from_zero &&
			(size_t)my_flags->f_precision < ft_strlen(value));
}

void tweak_flags_values(t_flag *my_flags, char *value, char conversion_char)
{
	if (special_case_one(my_flags, value, conversion_char))
    {
		my_flags->precision_from_zero = 0;
		my_flags->have_precision = 0;
		my_flags->f_max_width = my_flags->f_precision;
		my_flags->f_precision = 0;
	}
}
