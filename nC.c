#include <stdio.h>
#include "libft.h"

typedef struct s_flaf
{
	int			has_type;
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

	i = 1;
	while (format[i] && format[i] == '-')
		i++;
	if (i != 1)
		my_flags.has_type = 1;
	else
		my_flags.has_type = 0;
	my_flags.f_max_width = ft_atoi(format, &i);
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

char *ft_apply_width(t_flag my_flags, char *value)
{
	char *str;
	size_t value_lens;
	int i;

	i = -1;
	value_lens = ft_strlen(value);
	if (my_flags.f_max_width > value_lens)
	{
		str = ft_strnew_with_space(my_flags.f_max_width);
		if (!my_flags.has_type)
			while (value_lens)
				str[--my_flags.f_max_width] = value[--value_lens];
		else
			while (++i < value_lens)
				str[i] = value[i];
		return (str);
	}
	return (value);
}

char *ft_apply_precision(t_flag my_flags, char *str)
{
	char *new_str;
	int lens;

	lens = ft_strlen(str);
	if (my_flags.f_precision > lens)
	{
		new_str = ft_strnew_with_zero(my_flags.f_precision);
		if (new_str)
		{
			while (lens > 0)
				new_str[--my_flags.f_precision] = str[--lens];
			return (new_str);
		}
	}
	return (str);
}

char *ft_manage_flags(char *format, char *value)
{
	t_flag my_flags;
	char *str;

	my_flags = ft_initialize_attribution_flag(format);
	str = ft_apply_precision(my_flags, value);
	str = ft_apply_width(my_flags, str);

	return (str);
}



int main()
{
    char s[10] = "420888999";


//	char *s1 = ft_manage_flags("%.10d", "420888999");
//	char *s2 = ft_manage_flags("%.11d", "420888999");
//	char *s3 = ft_manage_flags("%19d", "420888999");
//	char *s4 = ft_manage_flags("%20d", "420888999");
	//printf("%s\n%s\n%s\n%s\n", s1,s2,s3,s4);
	printf("%s\n", ft_manage_flags("%1.1d", "420888999"));
	printf("%1.1d\n", 420888999);
	return (0);
}
