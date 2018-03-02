/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:32:04 by overetou          #+#    #+#             */
/*   Updated: 2018/02/28 18:34:13 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	test2_r(int *a, int la, int *b, int lb)
{
	if (la > 1 && a[0] > a[la - 1])
	{
		if (a[la - 1] < a[1])
		{
			ft_putendl("rra");
			ft_rrx(a, la);
		}
		else
		{
			ft_putendl("ra");
			ft_rx(a, la);
		}
		return (1);
	}
	else if (lb > 1 && b[0] < b[lb - 1])
	{
		ft_putendl("rb");
		ft_rx(b, lb);
		return (1);
	}
	return (0);
}

short	test2_s(int *a, int la, int *b, int lb)
{
	if (la > 1 && a[0] > a[1])
	{
		if (lb > 1 && b[0] < b[1])
		{
			ft_putendl("ss");
			ft_ss(a, la, b, lb);
		}
		else
		{
			ft_putendl("sa");
			ft_sx(a, la);
		}
		return (1);
	}
	else if (lb > 1 && b[0] < b[1])
	{
		ft_putendl("sb");
		ft_sx(b, lb);
		return (1);
	}
	return (0);
}

int		small(int *a, int *b, int la, int lb)
{
	while (!is_sorted(a, la))
	{
		if (!test2_s(a, la, b, lb))
		{
			if (!test2_r(a, la, b, lb))
			{
				ft_putendl("pb");
				ft_px(a, &la, b, &lb);
			}
		}
	}
	while (lb)
	{
		ft_putendl("pa");
		ft_px(b, &lb, a, &la);
		if (!is_sorted(a, la) || !is_sorted_r(b, lb))
			lb = solve(a, b, la, lb);
	}
	return (0);
}


