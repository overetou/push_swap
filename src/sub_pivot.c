/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:14:35 by overetou          #+#    #+#             */
/*   Updated: 2018/02/22 16:53:27 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sx(t_pile *x)
{
	t_pile	*next;
	int		tmp;

	next = x->next;
	tmp = x->n;
	x->n = next->n;
	next->n = tmp;
}

void	rx(t_pile **x)
{
	t_pile	*last;
	t_pile	*old;

	if (*x && (*x)->next)
	{
		old = *x;
		*x = (*x)->next;
		last = *x;
		while (last->next)
			last = last->next;
		last->next = old;
		old->next = NULL;
	}
}

void	rrx(t_pile **x)
{
	t_pile	*old;

	if (*x && (*x)->next)
	{
		old = *x;
		while ((*x)->next)
			*x = (*x)->next;
		(*x)->next = old;
		while (old->next != *x)
			old = old->next;
		old->next = NULL;
	}
}

void	px(t_pile **less, t_pile **more)
{
	t_pile	*old;
	
	old = *less;
	if (old->next)
		*less = (*less)->next;
	else
		*less = NULL;
	if (*more)
		old->next = *more;
	else
		old->next = NULL;
	*more = old;
}

void	ss(t_pile *a, t_pile *b)
{
	write(1, "ss\n", 3);
	sx(a);
	sx(b);
}

