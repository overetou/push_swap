#include "checker.h"

short	ft_sx(int *x, int lx)
{
	if (lx > 1)
		ft_swap_i(&x[0], &x[1]);
		return (1);
}

short	ft_px(int *x, int *lx, int *y, int *ly)
{
	int i;

	if (*lx)
	{
		i = (*ly) - 1;
		while (i != -1)
		{
			y[i + 1] = y[i];
			i--;
		}
		i = 0;
		y[0] = x[0];
		(*ly)++;
		while (i != *lx)
		{
			x[i] = x[i + 1];
			i++;
		}
		(*lx)--;
		ft_putnbr(*lx);
		ft_putnbr(*ly);
		ft_putchar('\n');
	}
	return (1);
}

void	dsp_stack(int *a, int *b, int la, int lb)
{
	int x;

	x = 0;
	while (x != la)
		ft_putnbr(a[x++]);
	x = 0;
	ft_putchar('\n');
	while (x != lb)
		ft_putnbr(b[x++]);
	ft_putchar('\n');
}

short	ft_rrx(int *x, int lx)
{
	int i;

	i = lx - 1;
	while (i != -1)
	{
		x[i + 1] = x[i];
		i--;
	}
	x[0] = x[lx];
	return (1);
}

short ft_rx(int *x, int lx)
{
	int i;

	x[lx] = x[0];
	i = 0;
	while (i != lx)
	{
		x[i] = x[i + 1];
		i++;
	}
	return (1);
}
