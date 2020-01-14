#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	char *s_hidden = "hi low\0don't print me lol\0";


//	ft_printf(".%.*s.\n", -30, "hello");
//	printf(".%.*s.\n", -30, "hello");

//	ft_printf(".%-*.*s.\n", -7, -3, "yolo");
//	printf(".%-*.*s.\n", -7, -3, "yolo");


 	ft_printf(".%5.%.\n");
	printf(".%5.%.\n");
	ft_printf(".%-5.%.\n");
	printf(".%-5.%.\n");
	ft_printf(".%05.%.\n");
	printf(".%05.%.\n");
	ft_printf(".%-05.%.\n");
	printf(".%-05.%.\n");

/*
ft_printf(".%5.p.\n", NULL);
ft_printf(".%5.p.\n", NULL);

ft_printf(".%2.p.\n", NULL);
ft_printf(".%2.p.\n", NULL);

ft_printf(".%9.2p.\n", 1234);
ft_printf(".%9.2p.\n", 1234);

ft_printf(".%2.9p.\n", 1234);
ft_printf(".%2.9p.\n", 1234);

ft_printf(".%.5p.\n", 0);
ft_printf(".%.5p.\n", 0);

ft_printf(".%.0p.\n", 0);
ft_printf(".%.0p.\n", 0);

ft_printf(".%5p.\n", 0);
ft_printf(".%5p.\n", 0);
*/

/*
ft_printf(".%5.%.\n");
printf(".%5.%.\n");

ft_printf(".%-5.%.\n");
printf(".%-5.%.\n");

ft_printf(".%05.%.\n");
printf(".%05.%.\n");

ft_printf(".%-05.%.\n");
printf(".%-05.%.\n");
*/


/*
ft_printf(".%p.\n",  NULL);
printf(".%p.\n",  NULL);

ft_printf(".%5p.\n",  NULL);
printf(".%5p.\n",  NULL);

ft_printf(".%2p.\n",  NULL);
printf(".%2p.\n",  NULL);

ft_printf(".%.p.\n",  NULL);
printf(".%.p.\n",  NULL);

ft_printf(".%5.p.\n",  NULL);
printf(".%5.p.\n",  NULL);

ft_printf(".%2.p.\n",  NULL);
printf(".%2.p.\n",  NULL);

ft_printf(".%05i.\n", -43);
printf(".%05i.\n", -43);

ft_printf(".%07i.\n", 54);
printf(".%07i.\n", 54);
ft_printf(".%07i.\n", -54);
printf(".%07i.\n", -54);

ft_printf(".%.10d.\n", 42);
printf(".%.10d.\n", 42);
ft_printf(".%.10d.\n", -42);
printf(".%.10d.\n", -42);

ft_printf(".%07d.\n", -54);
	printf(".%07d.\n", -54);

ft_printf(".%5%.\n");
	printf(".%5%.\n");

	ft_printf(".%08.5i.\n", 34);
	printf(".%08.5i.\n", 34);

ft_printf(".%05i.\n", -43);
printf(".%05i.\n", -43);

ft_printf(".%03i.\n", 0);
printf(".%03i.\n", 0);

ft_printf(".%03i.\n", 634);
printf(".%03i.\n", 634);

ft_printf(".%04i.\n", -532);
printf(".%04i.\n", -532);

ft_printf(".%04i.\n", -4825);
printf(".%04i.\n", -4825);

ft_printf(".%0-8.5i.\n", 34);
printf(".%0-8.5i.\n", 34);

ft_printf(".%0-10.5i.\n", -216);
printf(".%0-10.5i.\n", -216);

ft_printf(".%0-8.5i.\n", 0);
printf(".%0-8.5i.\n", 0);

ft_printf(".%0-8.3i.\n", 8375);
printf(".%0-8.3i.\n", 8375);

ft_printf(".%0-8.3i.\n", -8473);
printf(".%0-8.3i.\n", -8473);

ft_printf(".%0-3.7i.\n", 3267);
printf(".%0-3.7i.\n", 3267);

ft_printf(".%0-3.7i.\n", -2375);
printf(".%0-3.7i.\n", -2375);

ft_printf(".%0-3.3i.\n", 6983);
printf(".%0-3.3i.\n", 6983);

ft_printf(".%0-3.3i.\n", -8462);
printf(".%0-3.3i.\n", -8462);
*/
	return (0);
}

// l 153
