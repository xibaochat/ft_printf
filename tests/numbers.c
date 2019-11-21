#include <stdio.h>

char *ft_manage_flags(char *format, char *value, char c);

void test_nb_width(void)
{
	// BASIC WIDTH
	printf("1\n");
	printf(".%s.\n", ft_manage_flags("%10d", "420888999", 'd'));
	printf(".%10d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0d", "420888999", 'd'));;
	printf(".%0d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15d", "420888999", 'd'));;
	printf(".%15d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1d", "420888999", 'd'));;
	printf(".%1d.\n", 420888999);
	printf("-----------------------\n");

	// SIGNED WIDTH
	printf("2\n");
	printf(".%s.\n", ft_manage_flags("%-10d", "420888999", 'd'));;
	printf(".%-10d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0d", "420888999", 'd'));;
	printf(".%-0d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15d", "420888999", 'd'));;
	printf(".%-15d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1d", "420888999", 'd'));;
	printf(".%-1d.\n", 420888999);
	printf("-----------------------\n");
}

void test_nb_precision(void)
{
	// BASIC PRECISION
	printf("3\n");
	printf(".%s.\n", ft_manage_flags("%.10d", "420888999", 'd'));;
	printf(".%.10d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%.0d", "420888999", 'd'));;
	printf(".%.0d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%.15d", "420888999", 'd'));;
	printf(".%.15d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%.1d", "420888999", 'd'));;
	printf(".%.1d.\n", 420888999);
	printf("-----------------------\n");
}

void test_nb_precision_with_width(void)
{
	// BASIC WIDTH
	// PRECISION 0
	printf(".%s.\n", ft_manage_flags("%10.0d", "420888999", 'd'));;
	printf(".%10.0d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.0d", "420888999", 'd'));;
	printf(".%0.0d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.0d", "420888999", 'd'));;
	printf(".%15.0d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.0d", "420888999", 'd'));;
	printf(".%1.0d.\n", 420888999);
	printf("-----------------------\n");

	// PRECISION 10
	printf(".%s.\n", ft_manage_flags("%10.10d", "420888999", 'd'));;
	printf(".%10.10d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.10d", "420888999", 'd'));;
	printf(".%0.10d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.10d", "420888999", 'd'));;
	printf(".%15.10d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.10d", "420888999", 'd'));;
	printf(".%1.10d.\n", 420888999);
	printf("-----------------------\n");

	// PRECISION 15
	printf(".%s.\n", ft_manage_flags("%10.15d", "420888999", 'd'));;
	printf(".%10.15d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.15d", "420888999", 'd'));;
	printf(".%0.15d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.15d", "420888999", 'd'));;
	printf(".%15.15d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.15d", "420888999", 'd'));;
	printf(".%1.15d.\n", 420888999);
	printf("-----------------------\n");

	// PRECISION 1
	printf(".%s.\n", ft_manage_flags("%10.1d", "420888999", 'd'));;
	printf(".%10.1d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.1d", "420888999", 'd'));;
	printf(".%0.1d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.1d", "420888999", 'd'));;
	printf(".%15.1d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.1d", "420888999", 'd'));;
	printf(".%1.1d.\n", 420888999);
	printf("-----------------------\n");


	// SIGNED WIDTH
	// PRECISION 0
	printf(".%s.\n", ft_manage_flags("%-10.0d", "420888999", 'd'));;
	printf(".%-10.0d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.0d", "420888999", 'd'));;
	printf(".%-0.0d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.0d", "420888999", 'd'));;
	printf(".%-15.0d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.0d", "420888999", 'd'));;
	printf(".%-1.0d.\n", 420888999);
	printf("-----------------------\n");

	// PRECISION 10
	printf(".%s.\n", ft_manage_flags("%-10.10d", "420888999", 'd'));;
	printf(".%-10.10d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.10d", "420888999", 'd'));;
	printf(".%-0.10d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.10d", "420888999", 'd'));;
	printf(".%-15.10d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.10d", "420888999", 'd'));;
	printf(".%-1.10d.\n", 420888999);
	printf("-----------------------\n");

	// PRECISION 15
	printf(".%s.\n", ft_manage_flags("%-10.15d", "420888999", 'd'));;
	printf(".%-10.15d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.15d", "420888999", 'd'));;
	printf(".%-0.15d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.15d", "420888999", 'd'));;
	printf(".%-15.15d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.15d", "420888999", 'd'));;
	printf(".%-1.15d.\n", 420888999);
	printf("-----------------------\n");

	// PRECISION 1
	printf(".%s.\n", ft_manage_flags("%-10.1d", "420888999", 'd'));;
	printf(".%-10.1d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.1d", "420888999", 'd'));;
	printf(".%-0.1d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.1d", "420888999", 'd'));;
	printf(".%-15.1d.\n", 420888999);
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.1d", "420888999", 'd'));;
	printf(".%-1.1d.\n", 420888999);
	printf("-----------------------\n");
}
