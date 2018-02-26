/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:53:11 by overetou          #+#    #+#             */
/*   Updated: 2018/02/26 21:33:18 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


void	move_a(t_pile **a, t_pile **b, t_instr *itr)
{
	int median;
	int i;

	(*a)->stop = 0;
	while (!sorted(*a))
	{
		median = get_median(*a);
		i = 0;
		while ((*a)->next && !sorted(*a))
		{
			if ((*a)->n > median)
			{
				itr = rx(a, 'a', itr);
				i++;
			}
			else if ((*a)->n > ((*a)->next)->n)
				itr = sx(*a, 'a', itr);
			else
				itr = px(a, b, 'b', itr);
		}
		while (i--)
		{
			itr = rrx(a, 'a', itr);
			if ((*a)->n > ((*a)->next)->n)
				itr = sx(*a, 'a', itr);
		}
	}
	if (*b)
		move_b(a, b, itr);
}

t_instr	*add_instr(char *s, t_instr *old)
{
	t_instr	*new;

	new = (t_instr*)malloc(sizeof(t_instr));
	new->word = ft_makestr(s);
	new->next = NULL;
	old->next = new;
	return (new);
}

void	rm_instr(t_instr **instr)
{
	t_instr *old;

	while (*instr)
	{
		old = *instr;
		*instr = (*instr)->next;
		ft_strdel(&(old->word));
		free(old);
	}
}

void	process_instr(t_instr *my_itr)
{
	t_instr	*next_i;

	while (my_itr &&  my_itr->next)
	{
		next_i = my_itr->next;
		if (ft_strcmp(my_itr->word, "ra\n") == 0 && ft_strcmp(next_i->word, "rra\n") == 0)
			my_itr = next_i;
		else if (ft_strcmp(my_itr->word, "rb\n") == 0 && ft_strcmp(next_i->word, "rrb\n") == 0)
			my_itr = next_i;
		else if ((ft_strcmp(my_itr->word, "pa\n") == 0 && ft_strcmp(next_i->word, "pb\n") == 0
		) || (ft_strcmp(my_itr->word, "pb\n") == 0 && ft_strcmp(next_i->word, "pa\n") == 0))
			my_itr = next_i;
		else
			ft_putstr(my_itr->word);
		my_itr = my_itr->next;
	}
	if (my_itr)
		ft_putstr(my_itr->word);
}

