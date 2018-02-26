/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:39:27 by overetou          #+#    #+#             */
/*   Updated: 2018/02/26 17:41:43 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int		get_ind(int n, int *ind)
{
	int i;

	i = 0;
	while (ind[i] != n)
		i++;
	return (i);
}

t_pile	*new_link(int n)
{
	t_pile *new;

	new = (t_pile*)malloc(sizeof(t_pile));
	new->next = NULL;
	new->n = n;
	new->stop = 0;
	return (new);
}

t_pile	*new_stack(int *a, int la, int *ind)
{
	t_pile *new;
	t_pile *to_return;
	int i;

	i = 1;
	to_return = new_link(get_ind(a[0], ind));
	new = to_return;
	while (i != la)
	{
		new->next = new_link(get_ind(a[i++], ind));
		new = new->next;
	}
	return (to_return);
}

int		*dirty_sort(int *a, int la, int *b, int lb)
{
	int *ind;
	int i;

	i = 0;
	ind = (int*)malloc(sizeof(int) * la + 1);
	while (i != la)
	{
		ind[i] = a[i];
		i++;
	}
	solve(ind, b, la, lb);
	return (ind);
}

void	quick(int *pa, int la, int *pb)
{
	t_pile	*a;
	t_pile	*b;
	t_instr	*itr;
	t_instr *last;
	int	*ind;

	if (is_sorted(pa, la))
			return ;
	ind = dirty_sort(pa, la, pb, 0);
	a = new_stack(pa, la, ind);
	b = NULL;
	itr = (t_instr*)malloc(sizeof(t_instr));
	itr->word = ft_makestr("");
	itr->next = NULL;
	last = itr;
	last = empty_a(&a, &b, itr);
	if (b)
		move_b(&a, &b, last);
	pre_process_b(itr);
	pre_process_a(itr);
	process_instr(itr);
	rm_instr(&itr);
	free(a);
	free(ind);
}
