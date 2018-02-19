/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:14:48 by overetou          #+#    #+#             */
/*   Updated: 2018/02/19 19:57:36 by overetou         ###   ########.fr       */
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

void	pivot(int *a, int *b, int la, int lb)
{
	int *ind;
	int targ;
	int li;

	ind = dirty_sort(a, la, b, lb);
	li = la;
	while (!wheel_ok(a, la))
	{
		targ = find_next(a, la, ind);
		if (a[0] < ind[li / 2] || get_ind(a[0], ind) == get_ind(b[0], ind) + 1)
		{
			involve_b(a[0], b, lb);
			write(1, "pb\n", 3);
			ft_px(a, &la, b, &lb);
		}
		else if (a[0] > a[1] && a[0] != ind[li - 1] && a[0] != targ)
		{
			write(1, "sa\n", 3);
			ft_sx(a, la);
		}
		else if (targ != a[0] && targ != a[1])
			go_to_targ(targ, a, la);
		else
			go_to_targ_2(ind[get_ind(targ, ind) + 1], a, la, targ);
	}
	spin_til_ok(a, la, b, lb);
	empty_b(a, &la, b, &lb);
	//dsp_stack(a, la, b, lb);
	free(ind);
	if (is_sorted(a, la))
		ft_putendl("ok");
}

