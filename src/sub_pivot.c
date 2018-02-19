/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:14:35 by overetou          #+#    #+#             */
/*   Updated: 2018/02/19 20:35:54 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	step_til_ko(int targ, int *a, int la, int * ind)
{
	int i;
	int x;

	i = get_ind(targ, a);
	x = get_ind(targ, ind);

	while (--x == get_ind(a[(i - 1 < 0 ? la + i : i) - 1], ind))
		i--;
	return (ind[x]);
}


int	get_ind(int n, int *ind)
{
	int i;

	i = 0;
	while (ind[i] != n)
		i++;
	return (i);
}

int	find_next(int *a, int la, int *ind)
{
	int targ;
	int i;

	targ = a[0];
	i = 1;
	while(i != la)
	{
		if (a[i] > targ)
			targ = a[i];
		i++;
	}
	targ = step_til_ko(targ, a, la,  ind);
	return (targ);
}

void	go_to_targ(int targ, int *a, int la)
{
	int i;
	
	i = get_ind(targ, a);
	if (i > la / 2)
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

void	go_to_targ_2(int obj, int *a, int la, int targ)
{
	int i;
	
	i = get_ind(obj, a);
	if (i > la / 2)
	{
		if (targ == a[1])
		{
			write(1, "sa\n", 3);
			ft_sx(a, la);
		}
		write(1, "rra\n", 4);
		ft_rrx(a, la);
	}
	else
	{
		if (a[0] > a[1])
		{
			write(1, "sa\n", 3);
			ft_sx(a, la);
			return ;
		}
		if (a[1] != obj && a[2] != obj)
		{
			write(1, "ra\n", 3);
			ft_rx(a, la);
		}
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


