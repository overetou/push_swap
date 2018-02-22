#include "push_swap.h"
#include <stdio.h>

short	is_sorted_r(int *b, int lb)
{
	int x;

	if (lb < 2)
		return(1);
	x = 1;
	while (x != lb)
	{
		if (b[x - 1] < b[x])
			return (0);
		x++;
	}
	return (1);
}

int		only_int(char **argv, int argc)
{
	int x;
	char *del;

	x = 1;
	while (argc > x)
	{
		if (ft_strcmp((del = ft_itoa(ft_atoi(argv[x]))), argv[x]) != 0)
		{
			ft_strdel(&del);
			return (0);
		}
		ft_strdel(&del);
		x++;
	}
	return (1);
}

