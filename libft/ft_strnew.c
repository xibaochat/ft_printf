#include "libft.h"

char	*ft_strnew_with_space(int size)
{
	char *ptr;
	int  i;

	if (!(ptr = (char *)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = ' ';
	ptr[i] = '\0';
	return (ptr);
}
char    *ft_strnew_with_zero(int size)
{
	char *ptr;
	int  i;

	if (!(ptr = (char *)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = '0';
	ptr[i] = '\0';
	return (ptr);
}
