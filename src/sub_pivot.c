/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:14:35 by overetou          #+#    #+#             */
/*   Updated: 2018/02/26 17:47:12 by overetou         ###   ########.fr       */
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
	if (c == 'a')
		return (add_instr("pa\n", itr));
	return (add_instr("pb\n", itr));
}

void	pre_process_b(t_instr *itr)
{
	t_instr	*next_i;
	int b;

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
				(itr->word)[0] = '\0';
				(next_i->word)[0] = '\0';
				next_i = next_i->next;
				itr = itr->next;
			}
			itr = next_i;
		}
		else
			itr = itr->next;
	}
}

void	pre_process_a(t_instr *itr)
{
	t_instr	*next_i;
	int a;

	while (itr)
	{
		a = 0;
		if (ft_strcmp(itr->word, "ra\n") == 0)
		{
			next_i = itr;
			while (next_i && ft_strcmp(next_i->word, "ra\n") == 0)
			{
				a++;
				next_i = next_i->next;
			}
			while (next_i && ft_strcmp(next_i->word, "rra\n") == 0 && a--)
			{
				(itr->word)[0] = '\0';
				(next_i->word)[0] = '\0';
				next_i = next_i->next;
				itr = itr->next;
			}
			itr = next_i;
		}
		else
			itr = itr->next;
	}
}

