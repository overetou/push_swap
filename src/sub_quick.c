/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_quick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:14:35 by overetou          #+#    #+#             */
/*   Updated: 2018/02/28 20:19:38 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instr	*sx(t_pile *x, char c, t_instr *itr)
{
	t_pile	*next;
	int		tmp;

	next = x->next;
	tmp = x->n;
	x->n = next->n;
	next->n = tmp;
	if (c == 'a')
		return (add_instr("sa\n", itr));
	return (add_instr("sb\n", itr));
}

t_instr	*rx(t_pile **x, char c, t_instr *itr)
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
		if (c == 'a')
			return (add_instr("ra\n", itr));
		return (add_instr("rb\n", itr));
	}
	return (itr);
}

t_instr	*rrx(t_pile **x, char c, t_instr *itr)
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
		if (c == 'a')
			return (add_instr("rra\n", itr));
		return (add_instr("rrb\n", itr));
	}
	return (itr);
}

t_instr	*px(t_pile **less, t_pile **more, char c, t_instr *itr)
{
	t_pile	*old;

	if (!(*less))
		return (itr);
	old = *less;
	*less = (*less)->next;
	old->next = *more;
	*more = old;
	if (c == 'a')
		return (add_instr("pa\n", itr));
	return (add_instr("pb\n", itr));
}

void	pre_process_b(t_instr *itr)
{
	t_instr	*next_i;
	int		b;

	while (itr)
	{
		b = 0;
		if (ft_strcmp(itr->word, "rb\n") == 0)
		{
			next_i = itr;
			while (next_i && ft_strcmp(next_i->word, "rb\n") == 0)
			{
				b++;
				next_i = next_i->next;
			}
			while (next_i && ft_strcmp(next_i->word, "rrb\n") == 0 && b--)
			{
				slash_instr(itr->word, next_i->word);
				next_i = next_i->next;
				itr = itr->next;
			}
			itr = next_i;
		}
		else
			itr = itr->next;
	}
}
