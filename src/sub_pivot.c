/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:14:35 by overetou          #+#    #+#             */
/*   Updated: 2018/02/14 20:35:23 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_ind(int n, int *ind)
{
	int i;

	i = 0;
	while (ind[i] != n)
		i++;
	return (i);
}

short	targ_ok(int targ, int *a, int la, int *ind, int li)
{
	int p;
	int i;

	if (targ < ind[li / 2])
		return (1);
	p = get_ind(targ, a);
	i = get_ind(targ, ind);
	if (p == 0)
	{
		if (get_ind(a[la - 1], ind) != i - 1 && a[0] > a[1])
			return (1);
	}
	else if (p == la - 1)
	{
		if (get_ind(a[p - 1], ind) != i - 1 && a[p] > a[0])
			return (1);
	}
	else if (get_ind(a[p - 1], ind) != i - 1 && a[p] > a[p + 1])
		return (1);
	return (0);
}

int		find_next(int *a, int la, int *ind, int li)
{
	int forward;
	int backward;
	int best;

	forward = 0;
	backward = 1;
	while (backward != la + 1 && !targ_ok(a[la - backward], a, la, ind, li))
		backward++;
	if (backward == la + 1)
	{
		best = a[0];
		while (forward != la)
		{
			if (best > a[forward])
				best = a[forward];
			forward++;
		}
		return (best);
	}
	while (!targ_ok(a[forward], a, la, ind, li))
		forward++;
	return (backward < forward ? a[la - backward] : a[forward]);
}

void	go_to_targ(int targ, int *a, int la)
{
	int i;
	
	i = get_ind(targ, a);
	if (i > la / 2 - 1)
	{
		write(1, "rra\n", 4);
		ft_rrx(a, la);
	}
	else
	{
		write(1, "ra\n", 3);
		ft_rx(a, la);
	}
}

void	involve_b(int targ, int *b, int lb)
{
	int wanted;

	if (lb > 1)
	{
		wanted = find_point(targ, b, lb);
		spin_b(wanted, get_ind(wanted, b), b, lb);
	}
}


