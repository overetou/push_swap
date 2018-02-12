/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:32:19 by overetou          #+#    #+#             */
/*   Updated: 2018/02/12 20:56:53 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	ft_sx(int *x, int lx)
{
	if (lx > 1)
		ft_swap_i(&x[0], &x[1]);
	return (1);
}

short	ft_px(int *less, int *lless, int *more, int *lmore)
{
	int i;

	if (*lless)
	{
		i = (*lmore);
		(*lmore)++;
		while (i)
		{
			more[i] = more[i - 1];
			i--;
		}
		more[0] = less[0];
		i = 1;
		while (i != (*lless))
		{
			less[i - 1] = less[i];
			i++;
		}
		(*lless)--;
	}
	return (1);
}

void	dsp_stack(int *a, int la, int *b, int lb)
{
	int x;

	x = 0;
	while (x != la)
	{
		ft_putnbr(a[x++]);
		ft_putchar(' ');
	}
	ft_putstr("---/");
	ft_putnbr(la);
	ft_putchar('\n');
	x = 0;
	while (x != lb)
	{
		ft_putnbr(b[x++]);
		ft_putchar(' ');
	}
	ft_putstr("---/");
	ft_putnbr(lb);
	ft_putchar('\n');
}

short	ft_rrx(int *x, int lx)
{
	int i;
	int save;
	if (lx < 2)
		return (1);
	i = lx - 1;
	save = x[lx - 1];
	while (i)
	{
		x[i] = x[i - 1];
		i--;
	}
	x[0] = save;
	return (1);
}

short ft_rx(int *x, int lx)
{
	int i;
	int save;

	i = 1;
	save = x[0];
	while (i != lx)
	{
		x[i - 1] = x[i];
		i++;
	}
	x[lx - 1] = save;
	return (1);
}
