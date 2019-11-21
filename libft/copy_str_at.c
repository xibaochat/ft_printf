#include "libft.h"

void copy_at_the_end(char *value, char **new_value)
{
	int i;
	int j;

	i = ft_strlen(value) - 1;
	j = ft_strlen(*new_value) - 1;
	while (i >= 0)
		(*new_value)[j--] = value[i--];
}

void copy_at_the_beggining(char *value, char **new_value)
{
	int i;

	i = -1;
	while (value[++i])
		(*new_value)[i] = value[i];
}
