/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:53:11 by overetou          #+#    #+#             */
/*   Updated: 2018/02/24 20:46:25 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	move_a(t_pile **a, t_pile **b)
{
	int median;
	int i;

	(*a)->stop = 0;
	while (!sorted(*a) && ((*a)->next)->stop != 1)
	{
		median = get_median(*a);
		i = 0;
		while ((*a)->next && (*a)->stop != 1 && !sorted(*a) && ((*a)->next)->stop != 1)
		{
			if ((*a)->n > ((*a)->next)->n)
				sx(*a, 'a');
			else if ((*a)->n > median)
			{
				rx(a, 'a');
				i++;
			}
			else
				px(a, b, 'b');
		}
		while (i--)
		{
			rrx(a, 'a');
			if ((*a)->n > ((*a)->next)->n)
				sx(*a, 'a');
		}
	}
	if (*b)
		move_b(a, b);
}

//void	process_instr(t_instr *my_itr)
//{
//	char	*next;
//	while (my_itr->next)
//	{
//		ft_strcpy((my_itr->next)->w, next);
//		if (strcmp(my_itr->w, "sa\n" && strcmp(

