#include "push_swap.h"
#include <stdio.h>

short	is_sorted_r(int *b, int lb)
{
	int x;

	if (lb < 2)
		return(1);
	x = 0;
	while (x != lb)
	{
		if (b[x] < b[x + 1])
			return (0);
		x++;
	}
	return (1);
}

void	b_spin_til_ok(int *b, int lb)
{
	int i;
	
	if (is_sorted_r(b, lb))
		return ;
	if (lb == 2)
	{
		write(0, "sb\n", 3);
		ft_sx(b, lb);
		return ;
	}
	i = 1;
	while (b[i] < b[i - 1])
		i++;
	if (i > lb / 2)
	{
		while (i++ != lb)
		{
			write(0, "rrb\n", 4);
			ft_rrx(b, lb);
		}
	}
	else
	{
		while (i--)
		{
			write(0, "rb\n", 3);
			ft_rx(b, lb);
		}
	}
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

int		find_point(int target, int *b, int lb)
{
	int best;
	int i;

	i = 0;
	while (i != lb && b[i] > target)
		i++;
	if (i == lb)
	{
		i = 1;
		best = b[0];
		while (i != lb)
		{
			if (b[i] > best)
				best = b[i];
			i++;
		}
	}
	else
	{
		best = b[i];
		while (i != lb)
		{
			if (b[i] > best && b[i] < target)
				best = b[i];
			i++;
		}
	}
	return (best);
}

void	spin_b(int wanted, int i, int *b, int lb)
{
	if (i > lb / 2)
	{
		while (b[0] != wanted)
		{
			write(0, "rrb\n", 4);
			ft_rrx(b, lb);
		}
	}
	else
	{
		while (b[0] != wanted)
		{
			write(0, "rb\n", 3);
			ft_rx(b, lb);
		}
	}
}
