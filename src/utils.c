#include "push_swap.h"

int		only_int(char **argv, int argc)
{
	int x;

	x = 1;
	while (argc > x)
	{
		if (ft_strcmp(ft_itoa(ft_atoi(argv[x])), argv[x]) != 0)
			return (0);
		x++;
	}
	return (1);
}

