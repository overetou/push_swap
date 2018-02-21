#include "push_swap.h"

void	get_lowest(int *a, int *la, int *b, int *lb)
{
	int i;
	int best;

	i = 1;
	best = a[0];
	while (i != (*la))
	{
		if (a[i] < best)
			best = a[i];
		i++;
	}
	i = 0;
	while (a[i] != best)
	{
		write(1, "ra\n", 3);
		ft_rx(a, *la);
		dsp_stack(a, *la, b, *lb);
	}
	write (1, "pb\n", 3);
	ft_px(a, la, b, lb);
	dsp_stack(a, *la, b, *lb);
}

void	pivot(int *a, int *b, int la, int lb)
{
	if (la % 2)
		get_lowest(a, &la, b, &lb);
}
