/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:14:48 by overetou          #+#    #+#             */
/*   Updated: 2018/02/14 20:02:06 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <push_swap.h>

void	spin_til_ok(int *a, int la)
{
	int i;
	
	if (is_sorted(a, la))
		return ;
	i = 1;
	while (a[i] > a[i - 1])
		i++;
	if (i > la / 2)
	{
		while (i++ != la)
		{
			write(0, "rra\n", 4);
			ft_rrx(a, la);
		}
	}
	else
	{
		while (i--)
		{
			write(0, "ra\n", 3);
			ft_rx(a, la);
		}
	}
}

void	empty_b(int *a, int *la, int *b, int *lb)
{
	if ((*lb) > 1)
		b_spin_til_ok(b, (*lb));
	while (*lb)
	{
		write(0, "pa\n", 3);
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

	ind = dirty_sort(a, la, b, lb);
	while (!wheel_ok(a, la))
	{
		targ = find_next(a, la, ind, b);
		if (targ != a[0])
			go_to_targ(targ, a, la);
		else if (targ < ind[la / 2] || get_ind(targ, ind) == get_ind(b[0], ind) + 1)
		{
			involve_b(targ, b, lb);
			write(0, "pb\n", 3);
			ft_px(a, &la, b, &lb);
		}
		else
		{
			write(0, "sa\n", 3);
			ft_sx(a, la);
		}
	}
	spin_til_ok(a, la);
	empty_b(a, &la, b, &lb);
	dsp_stack(a, la, b, lb);
	free(ind);
}

