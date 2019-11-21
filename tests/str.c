#include <stdio.h>

char *ft_manage_flags(char *format, char *value, char c);

void test_str_width(void)
{
	// BASIC WIDTH
	printf("1\n");
	printf(".%s.\n", ft_manage_flags("%10s", "420888999", 's'));
	printf(".%10s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0s", "420888999", 's'));;
	printf(".%0s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15s", "420888999", 's'));;
	printf(".%15s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1s", "420888999", 's'));;
	printf(".%1s.\n", "420888999");
	printf("-----------------------\n");

	// SIGNED WIDTH
	printf("2\n");
	printf(".%s.\n", ft_manage_flags("%-10s", "420888999", 's'));;
	printf(".%-10s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0s", "420888999", 's'));;
	printf(".%-0s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15s", "420888999", 's'));;
	printf(".%-15s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1s", "420888999", 's'));;
	printf(".%-1s.\n", "420888999");
	printf("-----------------------\n");
}

void test_str_precision(void)
{
	// BASIC PRECISION
	printf("3\n");
	printf(".%s.\n", ft_manage_flags("%.10s", "420888999", 's'));;
	printf(".%.10s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%.0s", "420888999", 's'));;
	printf(".%.0s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%.15s", "420888999", 's'));;
	printf(".%.15s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%.1s", "420888999", 's'));;
	printf(".%.1s.\n", "420888999");
	printf("-----------------------\n");
}

void test_str_precision_with_width(void)
{
	// BASIC WIDTH
	// PRECISION 0
	printf(".%s.\n", ft_manage_flags("%10.0s", "420888999", 's'));;
	printf(".%10.0s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.0s", "420888999", 's'));;
	printf(".%0.0s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.0s", "420888999", 's'));;
	printf(".%15.0s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.0s", "420888999", 's'));;
	printf(".%1.0s.\n", "420888999");
	printf("-----------------------\n");

	// PRECISION 10
	printf(".%s.\n", ft_manage_flags("%10.10s", "420888999", 's'));;
	printf(".%10.10s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.10s", "420888999", 's'));;
	printf(".%0.10s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.10s", "420888999", 's'));;
	printf(".%15.10s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.10s", "420888999", 's'));;
	printf(".%1.10s.\n", "420888999");
	printf("-----------------------\n");

	// PRECISION 15
	printf(".%s.\n", ft_manage_flags("%10.15s", "420888999", 's'));;
	printf(".%10.15s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.15s", "420888999", 's'));;
	printf(".%0.15s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.15s", "420888999", 's'));;
	printf(".%15.15s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.15s", "420888999", 's'));;
	printf(".%1.15s.\n", "420888999");
	printf("-----------------------\n");

	// PRECISION 1
	printf(".%s.\n", ft_manage_flags("%10.1s", "420888999", 's'));;
	printf(".%10.1s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%0.1s", "420888999", 's'));;
	printf(".%0.1s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%15.1s", "420888999", 's'));;
	printf(".%15.1s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%1.1s", "420888999", 's'));;
	printf(".%1.1s.\n", "420888999");
	printf("-----------------------\n");


	// SIGNED WIDTH
	// PRECISION 0
	printf(".%s.\n", ft_manage_flags("%-10.0s", "420888999", 's'));;
	printf(".%-10.0s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.0s", "420888999", 's'));;
	printf(".%-0.0s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.0s", "420888999", 's'));;
	printf(".%-15.0s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.0s", "420888999", 's'));;
	printf(".%-1.0s.\n", "420888999");
	printf("-----------------------\n");

	// PRECISION 10
	printf(".%s.\n", ft_manage_flags("%-10.10s", "420888999", 's'));;
	printf(".%-10.10s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.10s", "420888999", 's'));;
	printf(".%-0.10s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.10s", "420888999", 's'));;
	printf(".%-15.10s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.10s", "420888999", 's'));;
	printf(".%-1.10s.\n", "420888999");
	printf("-----------------------\n");

	// PRECISION 15
	printf(".%s.\n", ft_manage_flags("%-10.15s", "420888999", 's'));;
	printf(".%-10.15s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.15s", "420888999", 's'));;
	printf(".%-0.15s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.15s", "420888999", 's'));;
	printf(".%-15.15s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.15s", "420888999", 's'));;
	printf(".%-1.15s.\n", "420888999");
	printf("-----------------------\n");

	// PRECISION 1
	printf(".%s.\n", ft_manage_flags("%-10.1s", "420888999", 's'));;
	printf(".%-10.1s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-0.1s", "420888999", 's'));;
	printf(".%-0.1s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-15.1s", "420888999", 's'));;
	printf(".%-15.1s.\n", "420888999");
	printf("-----------------------\n");

	printf(".%s.\n", ft_manage_flags("%-1.1s", "420888999", 's'));;
	printf(".%-1.1s.\n", "420888999");
	printf("-----------------------\n");
}
