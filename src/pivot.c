/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:39:27 by overetou          #+#    #+#             */
/*   Updated: 2018/02/22 16:52:32 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_pile	*new_link(int n)
{
	t_pile *new;

	new = (t_pile*)malloc(sizeof(t_pile));
	new->next = NULL;
	new->n = n;
	new->stop = 0;
	return (new);
}

t_pile	*new_stack(int *a, int la)
{
	t_pile *new;
	t_pile *to_return;
	int i;

	i = 1;
	to_return = new_link(a[0]);
	new = to_return;
	while (i != la)
	{
		new->next = new_link(a[i++]);
		new = new->next;
	}
	return (to_return);
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


void	quick(int *pa, int la)
{
	t_pile	*a;
	t_pile	*b;

	a = new_stack(pa, la);
	b = NULL;
	px(&a, &b);
	px(&a, &b);
	dsp(a, b);
	ss(b, a);
	dsp(a, b);
	free(a);
}
