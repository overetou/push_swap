/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:14:48 by overetou          #+#    #+#             */
/*   Updated: 2018/02/20 21:28:00 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <push_swap.h>
#include <stdio.h>

void	spin_til_ok(int *a, int la, int *b, int lb)
{
	int i;
	int best;
	
	if (lb > 1)
		b_spin_til_ok(b, lb);
	i = 1;
	best = a[0];
	while (i != la)
	{
		if (a[i] > b[0] && a[i] < best)
			best = a[i];
		i++;
	}
	i = get_ind(best, a);
	if (i > la / 2)
	{
		while (i++ != la)
		{
			write(1, "rra\n", 4);
			ft_rrx(a, la);
		}
	}
	else
	{
		while (i--)
		{
			write(1, "ra\n", 3);
			ft_rx(a, la);
		}
	}
}

void	empty_b(int *a, int *la, int *b, int *lb)
{
	while (*lb)
	{
		while (a[(*la) - 1] > b[0] && a[(*la) - 1] < a[(*la) - 2])
		{
			write(1, "rra\n", 4);
			ft_rrx(a, *la);
		}
		write(1, "pa\n", 3);
		ft_px(b, lb, a, la);
	}
}

int		*dirty_sort(int *a, int la, int *b, int lb)
{
	int *ind;
	int i;

	i = 0;
	ind = (int*)malloc(sizeof(int) * la + 1);
	while (i != la)
	{
		ind[i] = a[i];
		i++;
	}
	solve(ind, b, la, lb);
	return (ind);
}

short	wheel_ok(int *a, int la)
{
	int i;
	int n;

	i = 1;
	n = 0;
	if (a[0] > a[la - 1])
		n++;
	while (i != la)
	{
		if (a[i] > a[i - 1])
			n++;
		i++;
	}
	if (n != la - 1)
		return (0);
	return (1);
}

void	fill_b(int *a, int *b, int la, int lb)
{
	int lim;

	lim = la / 2;
	while (lb != lim

void	pivot(int *a, int *b, int la, int lb)
{
	int targ;

	while (!wheel_ok(a, la))
	{

	}
}

