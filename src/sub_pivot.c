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

	i = get_ind(target, a);
	if (i > la / 2 - 1)
	{
		write(0, "rra\n", 4);
		ft_rrx(a, la);
	}
	else
	{
		write(0, "ra\n", 3);
		ft_rx(a, la);
	}
}

void	involve_b(int target, int *b, int lb)
{
	int i;
	int save;

	i = 0;
	if (lb > 1)
	{
		while (i != lb && target > b[i])
			i++;
		save = b[i]
		if (i > lb / 2 - 1)
			while
	}
	return (0);
}


