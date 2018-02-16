#include "push_swap.h"
#include <stdlib.h>

short	test_r(int *a, int la, int *b, int lb)
{
	if (la > 1 && a[0] > a[la - 1])
	{
		if (a[la - 1] < a[1])
			ft_rrx(a, la);
		else if (lb > 1  && b[0] < b[lb - 1])
			ft_rr(a, la, b, lb);
		else
			ft_rx(a, la);
		return (1);
	}
	else if (lb > 1 && b[0] < b[lb - 1])
	{
		ft_rx(b,lb);
		return (1);
	}
	return (0);
}

short	test_s(int *a, int la, int *b, int lb)
{
	if (la > 1 && a[0] > a[1])
	{
		if (lb > 1  && b[0] < b[1])
			ft_ss(a, la, b, lb);
		else
			ft_sx(a, la);
		return (1);
	}
	else if (lb > 1 && b[0] < b[1])
	{
		ft_sx(b,lb);
		return (1);
	}
	return (0);
}

int		solve(int *a, int *b, int la, int lb)
{
	while (!is_sorted(a, la))
	{
		if (!test_s(a, la, b, lb))
		{
			if (!test_r(a, la, b, lb))
				ft_px(a, &la, b, &lb);
		}
	}
	while (lb)
	{
		ft_px(b, &lb, a, &la);
		if (!is_sorted(a, la) || !is_sorted_r(b, lb))
			lb = solve(a, b, la, lb);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int x;
	int *a;
	int *b;

	if (argc == 1)
		return (0);
	if (only_int(argv, argc))
	{
		x = 1;
		a = (int*)malloc(sizeof(int) * argc);
		b = (int*)malloc(sizeof(int) * argc);
		while (x != argc)
		{
			a[x - 1] = ft_atoi(argv[x]);
			x++;
		}
		no_double_i(a, argc - 1) ? pivot(a, b, argc - 1, 0) : ft_putendl("ERROR");
		free(a);
		free(b);
	}
	else
		ft_putendl("ERROR");
	return (0);
}
