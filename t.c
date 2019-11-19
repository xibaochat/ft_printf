
#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

void baby_printf(char *str, ...)
{
	va_list p_list;

	va_start(p_list, str);
	int i;
	int j;
	char *s;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = i + 1;
			if (str[j] == 'd' || str[j] == 'i')
				ft_putnbr(va_arg(p_list, int));
			else if (str[j] == 's')
				ft_putstr(va_arg(p_list, char *));
			else if (str[j] == 'c')
				ft_putchar(va_arg(p_list, int));
			else if (str[j] == 'u')
				ft_put_unsigned_nbr(va_arg(p_list, unsigned int));
			else if (str[j] == 'x')
				ft_putstr(ft_trans_to_x(va_arg(p_list, int)));
			else if (str[j] == 'X')
				ft_putstr(ft_trans_to_X((va_arg(p_list, int))));
			else if (str[j] == 'p')
			{
				ft_putstr("0x");
				s = ft_ptr(va_arg(p_list, void *));
				ft_putstr(s);
			}
			else if (str[j] == '%')
			{
				ft_putchar('%');
				ft_putchar(str[i]);
			}
			++i;
		}
		else
			ft_putchar(str[i]);
			i++;
	}
	va_end(p_list);
}

int main(void)
{
	printf("%p %s %c %s %%d\n", 42, "kitten", 'x', "xibaoxiaomaomi");
/*	int a = 15;
	unsigned int ptr = *((unsigned int*) &a);
	ft_putchar(*(1+ unsigned char*) &ptr));
	ft_putchar(*((unsigned char*) &ptr));*/
	return (0);
}
