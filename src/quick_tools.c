/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:44:54 by overetou          #+#    #+#             */
/*   Updated: 2018/02/28 19:22:25 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

short	sorted(t_pile *a)
{
	if (a && a->next)
	{
		if ((a->next)->stop == 1 || sorted(a->next))
		{
			if ((a->next)->n == a->n + 1)
			{
				a->stop = 1;
				return (1);
			}
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
		if (a->stop == 1)
			write(1, "*", 1);
		write(1, " ", 1);
		a = a->next;
	}
	write(1, "\n", 1);
	if (b)
	{
		while (b)
		{
			ft_putnbr(b->n);
			if (b->stop == 1)
				write(1, "*", 1);
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
	int i;

	i = 0;
	best = a->n;
	lowest = best;
	a = a->next;
	while (a && a->stop != 1)
	{
		i++;
		if (a->n > best)
			best = a->n;
		else if (a->n < lowest)
			lowest = a->n;
		a = a->next;
	}
	if (i < 2)
		return (lowest);
	return (lowest + ((best - lowest) / 2));
}

void	move_b(t_pile **a, t_pile **b, t_instr *itr)
{
	int median;
	int i;

	i = 0;
	(*b)->stop = 0;
	median = get_median(*b);
	while (*b && (*b)->stop != 1)
	{
		if ((*b)->n < median && (*b)->next)
		{
			itr = rx(b, 'b', itr);
			i++;
		}
		else if (*b && (*b)->next && (*b)->n < ((*b)->next)->n)
			itr = sx(*b, 'b', itr);
		else
			itr = px(b, a, 'a', itr);
	}
	while (i--)
		rr_test_sb(b, &itr);
	(*a)->stop = 1;
	if (*b)
		(*b)->stop = 1;
	move_a(a, b, itr);
}

t_instr	*empty_a(t_pile **a, t_pile **b, t_instr *itr)
{
	int		median;
	t_pile	*last;
	int		mark;

	while (!sorted_lite(*a))
	{
		last = *a;
		while (last->next)
			last = last->next;
		mark = last->n;
		median = get_median(*a);
		while ((*a)->n != mark)
			itr = ((*a)->n >= median ? rx(a, 'a', itr) : px(a, b, 'b', itr));
		if ((*a)->n < median)
			itr = px(a, b, 'b', itr);
		if (*b)
			(*b)->stop = 1;
	}
	if (!*b)
		return (itr);
	last = *b;
	while (last->next)
		last = last->next;
	last->stop = 1;
	return (itr);
}
