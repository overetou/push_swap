#include "push_swap.h"

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

