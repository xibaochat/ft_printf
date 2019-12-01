#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libftprintf.h"

char	*ptr_to_str(void *ptr)
{
	uintmax_t	p;

	p = (uintmax_t)ptr;
	return (ft_trans_to_x(p));
}
