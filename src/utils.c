/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:39:03 by overetou          #+#    #+#             */
/*   Updated: 2018/02/28 18:43:32 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

short	is_sorted_r(int *b, int lb)
{
	int x;

	if (lb < 2)
		return (1);
	x = 1;
	while (x != lb)
	{
		if (b[x - 1] < b[x])
			return (0);
		x++;
	}
	return (1);
}

int		only_int(char *s)
{
	char *del;

	if (ft_strcmp((del = ft_itoa(ft_atoi(s))), s) != 0)
	{
		ft_strdel(&del);
		return (0);
	}
	ft_strdel(&del);
	return (1);
}

int		count_arg(int argc, char **argv)
{
	int p;
	int i;
	int n;

	p = 1;
	n = 0;
	while (p != argc)
	{
		i = 0;
		while (argv[p][i])
		{
			while (argv[p][i] && argv[p][i] == ' ')
				i++;
			if (argv[p][i])
			{
				n++;
				while (argv[p][i] && argv[p][i] != ' ')
					i++;
			}
		}
		p++;
	}
	return (n);
}

short	set_a(int *a, char **argv, int argc)
{
	int		n;
	int		p;
	int		x;
	char	**tmp;

	n = 0;
	p = 1;
	while (n != argc)
	{
		tmp = ft_strsplit(argv[p], ' ');
		x = 0;
		while (tmp[x])
		{
			if (!only_int(tmp[x]))
				return (0);
			a[n] = ft_atoi(tmp[x]);
			ft_strdel(&tmp[x]);
			x++;
			n++;
		}
		free(tmp);
		p++;
	}
	return (1);
}

short	sorted_lite(t_pile *a)
{
	if (a && a->next)
	{
		if (sorted_lite(a->next))
		{
			if ((a->next)->n == a->n + 1)
				return (1);
		}
		return (0);
	}
	return (1);
}
