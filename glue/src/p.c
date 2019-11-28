#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

char	*ft_ptr(void *ptr)
{
	uintmax_t	p;

	p = (uintmax_t)ptr;
	return (ft_trans_to_x(p));
}
