/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:14:35 by overetou          #+#    #+#             */
/*   Updated: 2018/02/23 13:29:19 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sx(t_pile *x, char c)
{
	t_pile	*next;
	int		tmp;

	next = x->next;
	tmp = x->n;
	x->n = next->n;
	next->n = tmp;
	ft_putchar('s');
	ft_putchar(c);
	ft_putchar('\n');
}

void	rx(t_pile **x, char c)
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
	ft_putchar('r');
	ft_putchar(c);
	ft_putchar('\n');
	}
}

void	rrx(t_pile **x, char c)
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
	ft_putstr("rr");
	ft_putchar(c);
	ft_putchar('\n');
	}
}

void	px(t_pile **less, t_pile **more, char c)
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
	ft_putchar('p');
	ft_putchar(c);
	ft_putchar('\n');
}

void	ss(t_pile *a, t_pile *b)
{
	write(1, "ss\n", 3);
	sx(a, 'a');
	sx(b, 'b');
}

