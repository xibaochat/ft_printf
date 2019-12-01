#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libftprintf.h"

char	*ptr_to_str(void *ptr)
{
	uintmax_t	p;
	char *new;

	p = (uintmax_t)ptr;
	if (!p)
	{
		new = ft_strnew(6);
		ft_strcat(new, "(nil)");
		return (new);
	}
	return (ft_trans_to_x(p));
}
