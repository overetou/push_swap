/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:14:35 by overetou          #+#    #+#             */
/*   Updated: 2018/02/14 18:16:32 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int		get_ind(int n, int *ind)
{
	int i;

	i = 0;
	while (ind[i] != target)
		i++;
	return (i);
}

short	target_ok(int target, int *a, int la, int *ind)
{
	int p;
	int i;

	if (target < ind[la / 2])
		return (1);
	p = get_ind(target, a);
	i = get_ind(target, ind);
	if (p == 0)
	{
		if (get_ind(a[la - 1], ind) != i - 1 && get_ind(a[1], ind) < i)
		return (1);
	}
	else if (p == la - 1)
	{
		if (get_ind(a[p - 1], ind) != i - 1 && get_ind(a[0], ind) < i)
			return (1);
	}
	else if (get_ind(a[p - 1], ind) != i - 1 && get_ind(a[p + 1], ind) < i)
		return (1);
	return (0);
}

int		find_next(int *a, int la, int *ind)
{
	int forward;
	int backward;

	forward = 0;
	backward = 1;
	while (!target_ok(a[forward], a, la, ind))
		forward++;
	while (!target_ok(a[la - backward], a, la, ind))
		backward++;
	return (backward < forward ? a[la - backward] : a[forward]);
}

void	go_to_target(int target,int *a, int la)
{
	int i;

	i = 0;
	while (target != a[i])
		i++;
	if (i > la / 2 - 1)
	{
		while (target != a[0])
		{
			write(0, "rra\n", 4);
			ft_rrx(a, la);
		}
	}
	else
	{
		while (target != a[0])
		{
			write(0, "ra\n", 3);
			ft_rx(a, la);
		}
	}
}

void	b_involved(int *a, int *la, int *b, int *lb)
{
	write(0, "pb\n", 3);
	ft_px(a, la, b, lb);
	while (!wheel_ok)
	{
		if (b[0] < b[1])
		{
			write(0, "sb\n", 3);
			ft_sx(b, lb);
		}
		else if (b[0] < b [lb- 1])
		{
			write(0, "rb\n", 3);
			ft_rx(b, lb);
		}
	}
	return (0);
}


