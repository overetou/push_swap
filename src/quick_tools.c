/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:16:22 by overetou          #+#    #+#             */
/*   Updated: 2018/02/22 22:01:35 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	sorted(t_pile *a)
{
	if (a->next)
	{
		if ((a->next)->stop == 2 || sorted(a->next))
		{
			if ((a->next)->n > a->n)
				return (1);
		}
		return (0);
	}
	return (1);
}

void	dsp(t_pile *a, t_pile *b)
{
	while (a)
	{
		ft_putnbr(a->n);
		write(1, " ", 1);
		a = a->next;
	}
	write(1, "\n", 1);
	if (b)
	{
		while (b)
		{
			ft_putnbr(b->n);
			write(1, " ", 1);
			b = b->next;
		}
		write(1, "\n", 1);
	}
}

int		get_median(t_pile *a)
{
	int best;
	int lowest;

	best = a->n;
	lowest = best;
	a = a->next;
	while (a && a->stop != 1)
	{
		if (a->n > best)
			best = a->n;
		else
			lowest = a->n;
		a = a->next;
	}
	return (lowest + ((best - lowest) / 2));
}

void	empty_a(t_pile **a, t_pile **b)
{
	int		median;
	t_pile	*last;
	int		mark;

	while (!sorted(*a))
	{
		last = *a;
		while (last->next)
			last = last->next;
		mark = last->n;
		median = get_median(*a);
		while ((*a)->n != mark)
		{
			if ((*a)->n >= median)
				rx(a);
			else
				px(a, b);
		}
	}
}
