#include "libswap.h"

int	main(int ac, char **av)
{
	int x = 0;

	while (*av[1] >= '0' && *av[1] <= '9')
		x = x * 10 + *av[1]++ - 48;
	while (x > 0)
	{
		printf("%ld ", random());
		x--;
	}
}