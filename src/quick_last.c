/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:55:19 by overetou          #+#    #+#             */
/*   Updated: 2018/02/28 20:24:41 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_test_sa(t_pile **a, t_instr **itr)
{
	*itr = rrx(a, 'a', *itr);
	if ((*a)->n > ((*a)->next)->n)
		*itr = sx(*a, 'a', *itr);
}

void	slash_instr(char *s1, char *s2)
{
	s1[0] = '\0';
	s2[0] = '\0';
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
