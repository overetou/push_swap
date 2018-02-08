#include "../libft/libft.h"
#include "../checkerD/checker.h"

short	is_sorted_r(int *b, int lb)
{
	int x;

	x = 0;
	if (lb < 2)
		return(1);
	while (x != lb)
	{
		if (b[x] < b[x + 1])
			return (0);
		x++;
	}
	return (1);
}

short	test_r(int *a, int la, int *b, int lb)
{
	if (la > 1 && a[0] > a[la - 1])
	{
		if (lb > 1  && b[0] < b[lb - 1])
		{
			ft_putstr("rr\n");
			ft_rr(a, la, b, lb);
		}
		else
		{
			ft_putstr("ra\n");
			ft_rx(a, la);
		}
		return (1);
	}
	else if (lb > 1 && b[0] < b[lb - 1])
	{
		ft_putstr("rb\n");
		ft_rx(b,lb);
		return (1);
	}
	return (0)
}

short	test_s(int *a, int la, int *b, int lb)
{
	if (la > 1 && a[0] > a[1])
	{
		if (lb > 1  && b[0] < b[1])
		{
			ft_putstr("ss\n");
			ft_ss(a, la, b, lb);
		}
		else
		{
			ft_putstr("sa\n");
			ft_sx(a, la);
		}
		return (1);
	}
	else if (lb > 1 && b[0] < b[1])
	{
		ft_putstr("sb\n");
		ft_sx(b,lb);
		return (1);
	}
	return (0)
}

void	solve(int *a, int *b, int la)
{
	int lb;

	lb = 0;
	while (!is_sorted(a, la) && is_sorted_r(b, lb))
	{
		if (!test_r(a, la, b, lb))
		{
			if (!test_sx(a, la, b, lb))
			{
				ft_putstr("pb\n");
				ft_px(a, &la, b, &lb);
			}
		}
	}
	while (lb > 1)
	{
		ft_putstr("pa");
		ft_px(b, &lb, a, &la);
	}
}

int	main(int argc, char **argv)
{
	int x;

	if (argc == 1)
		return (0);
	x = 0:
	a = (int*)malloc(sizeof(int) * argc);
	b = (int*)malloc(sizeof(int) * argc);
	while (x != argc)
	{
		a[x] = ft_atoi(argv[x + 1]);
		x++;
	}
	solve(a, b, argc - 1);
	free(a);
	free(b);
}
