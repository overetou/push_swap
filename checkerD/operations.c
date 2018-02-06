/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:32:19 by overetou          #+#    #+#             */
/*   Updated: 2018/02/06 16:00:01 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		i = (*lmore) - 1;
		while (i != -1)
		{
			more[i + 1] = more[i];
			i--;
		}
		more[0] = less[0];
		(*lmore)++;
		i = 0;
		while (i < (*lless))
		{
			less[i] = less[i + 1];
			i++;
		}
		(*lless)--;
	}
	return (1);
}

void	dsp_stack(int *a, int *b, int la, int lb)
{
	int x;

	x = 0;
	while (x != la)
		ft_putnbr(a[x++]);
	ft_putchar('\n');
	x = 0;
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
