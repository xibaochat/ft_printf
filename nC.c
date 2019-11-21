#include <stdio.h>
#include "libft.h"

typedef struct s_flaf
{
	int			is_signed;
	int			f_max_width;
	int			f_precision;
}				t_flag;

int ft_atoi(char *str, int *i)
{
	int s;

	s = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		s = s * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (s);
}

t_flag	ft_initialize_attribution_flag(char *format)
{
	int i;
	t_flag my_flags;

	// INIT WIDTH
	i = 1;
	while (format[i] && format[i] == '-')
		i++;
	if (i != 1)
		my_flags.is_signed = 1;
	else
		my_flags.is_signed = 0;
	my_flags.f_max_width = ft_atoi(format, &i);

	// INIT PRECISION
	if (format[i] == '.')
	{
		i++;
		my_flags.f_precision = ft_atoi(format, &i);
	}
	else
		my_flags.f_precision = 0;
	return my_flags;
}

int char_is_n(char c)
{
	return (c == 'p' || c == 'x' ||
			c == 'X' || c == 'd' || c == 'i' || c == 'u');
}

char *ft_apply_precision(t_flag my_flags, char *value)
{
	char *new_value;

	new_value = ft_strnew_with_char(my_flags.f_precision, '0');
	copy_at_the_end(value, &new_value);
	return (new_value);
}

char *ft_apply_unsigned_width(t_flag my_flags, char *value)
{
	char *new_value;

	new_value = ft_strnew_with_char(my_flags.f_max_width, ' ');
	copy_at_the_end(value, &new_value);
	return (new_value);
}

char *ft_apply_signed_width(t_flag my_flags, char *value)
{
	char *new_value;

	new_value = ft_strnew_with_char(my_flags.f_max_width, ' ');
	copy_at_the_beggining(value, &new_value);
	return (new_value);
}


char *ft_manage_flags(char *format, char *value)
{
	t_flag my_flags;
	int		v_len;
	char *new_value;


	my_flags = ft_initialize_attribution_flag(format);
	v_len = ft_strlen(value);
	new_value = value;

	if (my_flags.f_precision > v_len)
		new_value = ft_apply_precision(my_flags, value);
	if (my_flags.f_max_width > v_len && !my_flags.is_signed)
		new_value = ft_apply_unsigned_width(my_flags, new_value);
	else if (my_flags.f_max_width > v_len && my_flags.is_signed)
		new_value = ft_apply_signed_width(my_flags, new_value);


	return (new_value);
}



int main()
{
    char s[10] = "420888999";


//	char *s1 = ft_manage_flags("%.10d", "420888999");
//	char *s2 = ft_manage_flags("%.11d", "420888999");
//	char *s3 = ft_manage_flags("%19d", "420888999");
//	char *s4 = ft_manage_flags("%20d", "420888999");
	//printf("%s\n%s\n%s\n%s\n", s1,s2,s3,s4);

	printf(".%s.\n", ft_manage_flags("%-15d", "420888999"));
	printf(".%-15d.\n", 420888999);
	return (0);
}
