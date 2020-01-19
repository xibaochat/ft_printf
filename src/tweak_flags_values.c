#include "libftprintf.h"

/*
  Special case (e.g. %03s) where the given string is lower than
  the precision.
  In that case we consider the flag as width, not precision.
*/

void tweak_flags_values(t_flag *my_flags, char *value, char conversion_char)
{
    if (conversion_char == 's' &&
		my_flags->precision_from_zero &&
        (size_t)my_flags->f_precision < ft_strlen(value))
    {
		my_flags->precision_from_zero = 0;
		my_flags->have_precision = 0;
		my_flags->f_max_width = my_flags->f_precision;
		my_flags->f_precision = 0;
	}
}
