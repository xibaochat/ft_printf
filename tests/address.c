#include <stdio.h>
#include "libft.h"

char *ft_manage_flags(char *format, char *value, char c);

void test_ptr_width(void)
{
	char *s;

	// BASIC WIDTH
	printf("1\n");
	printf(".%s.\n", ft_manage_flags("%10p", ft_ptr((void *)&s), 'p'));
	printf(".%10p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0p", ft_ptr((void *)&s), 'p'));;
	printf(".%0p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15p", ft_ptr((void *)&s), 'p'));;
	printf(".%15p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1d", ft_ptr((void *)&s), 'p'));;
	printf(".%1p.\n", &s);
	printf("-----------------------\n");

	// SIGNED WIDTH
	printf("2\n");
	printf(".%s.\n", ft_manage_flags("%-10p", ft_ptr((void *)&s), 'p'));;
	printf(".%-10p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0p", ft_ptr((void *)&s), 'p'));;
	printf(".%-0p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15p", ft_ptr((void *)&s), 'p'));;
	printf(".%-15p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1d", ft_ptr((void *)&s), 'p'));;
	printf(".%-1p.\n", &s);
	printf("-----------------------\n");
}

void test_ptr_precision(void)
{
	char *s;

	// BASIC PRECISION
	printf("3\n");
	printf(".%s.\n", ft_manage_flags("%.10p", ft_ptr((void *)&s), 'p'));;
	printf(".%.10p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%.0p", ft_ptr((void *)&s), 'p'));;
	printf(".%.0p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%.15p", ft_ptr((void *)&s), 'p'));;
	printf(".%.15p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%.1d", ft_ptr((void *)&s), 'p'));;
	printf(".%.1p.\n", &s);
	printf("-----------------------\n");
}

void test_ptr_precision_with_width(void)
{
	char *s;

	// BASIC WIDTH
	// PRECISION 0
	printf(".%s.\n", ft_manage_flags("%10.0p", ft_ptr((void *)&s), 'p'));;
	printf(".%10.0p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.0p", ft_ptr((void *)&s), 'p'));;
	printf(".%0.0p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.0p", ft_ptr((void *)&s), 'p'));;
	printf(".%15.0p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.0p", ft_ptr((void *)&s), 'p'));;
	printf(".%1.0p.\n", &s);
	printf("-----------------------\n");

	// PRECISION 10
	printf(".%s.\n", ft_manage_flags("%10.10p", ft_ptr((void *)&s), 'p'));;
	printf(".%10.10p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.10p", ft_ptr((void *)&s), 'p'));;
	printf(".%0.10p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.10p", ft_ptr((void *)&s), 'p'));;
	printf(".%15.10p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.10p", ft_ptr((void *)&s), 'p'));;
	printf(".%1.10p.\n", &s);
	printf("-----------------------\n");

	// PRECISION 15
	printf(".%s.\n", ft_manage_flags("%10.15p", ft_ptr((void *)&s), 'p'));;
	printf(".%10.15p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.15p", ft_ptr((void *)&s), 'p'));;
	printf(".%0.15p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.15p", ft_ptr((void *)&s), 'p'));;
	printf(".%15.15p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.15p", ft_ptr((void *)&s), 'p'));;
	printf(".%1.15p.\n", &s);
	printf("-----------------------\n");

	// PRECISION 1
	printf(".%s.\n", ft_manage_flags("%10.1d", ft_ptr((void *)&s), 'p'));;
	printf(".%10.1p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.1d", ft_ptr((void *)&s), 'p'));;
	printf(".%0.1p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.1d", ft_ptr((void *)&s), 'p'));;
	printf(".%15.1p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.1d", ft_ptr((void *)&s), 'p'));;
	printf(".%1.1p.\n", &s);
	printf("-----------------------\n");


	// SIGNED WIDTH
	// PRECISION 0
	printf(".%s.\n", ft_manage_flags("%-10.0p", ft_ptr((void *)&s), 'p'));;
	printf(".%-10.0p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.0p", ft_ptr((void *)&s), 'p'));;
	printf(".%-0.0p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.0p", ft_ptr((void *)&s), 'p'));;
	printf(".%-15.0p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.0p", ft_ptr((void *)&s), 'p'));;
	printf(".%-1.0p.\n", &s);
	printf("-----------------------\n");

	// PRECISION 10
	printf(".%s.\n", ft_manage_flags("%-10.10p", ft_ptr((void *)&s), 'p'));;
	printf(".%-10.10p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.10p", ft_ptr((void *)&s), 'p'));;
	printf(".%-0.10p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.10p", ft_ptr((void *)&s), 'p'));;
	printf(".%-15.10p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.10p", ft_ptr((void *)&s), 'p'));;
	printf(".%-1.10p.\n", &s);
	printf("-----------------------\n");

	// PRECISION 15
	printf(".%s.\n", ft_manage_flags("%-10.15p", ft_ptr((void *)&s), 'p'));;
	printf(".%-10.15p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.15p", ft_ptr((void *)&s), 'p'));;
	printf(".%-0.15p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.15p", ft_ptr((void *)&s), 'p'));;
	printf(".%-15.15p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.15p", ft_ptr((void *)&s), 'p'));;
	printf(".%-1.15p.\n", &s);
	printf("-----------------------\n");

	// PRECISION 1
	printf(".%s.\n", ft_manage_flags("%-10.1d", ft_ptr((void *)&s), 'p'));;
	printf(".%-10.1p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.1d", ft_ptr((void *)&s), 'p'));;
	printf(".%-0.1p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.1d", ft_ptr((void *)&s), 'p'));;
	printf(".%-15.1p.\n", &s);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.1d", ft_ptr((void *)&s), 'p'));;
	printf(".%-1.1p.\n", &s);
	printf("-----------------------\n");
}
