/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:59:22 by overetou          #+#    #+#             */
/*   Updated: 2018/02/28 18:08:26 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

int		ft_exec(int *a, int *b, int la, short x)
{
	int		lb;
	char	*line;

	lb = 0;
	while (get_next_line(0, &line) && x)
	{
		x = 0;
		if (ft_strcmp(line, "pa") == 0)
	  		x = ft_px(b, &lb, a, &la);
		else if (ft_strcmp(line, "pb") == 0)
		 	x = ft_px(a, &la, b, &lb);
		else if (line[1] == 'a' || line[2] == 'a')
			x = ft_a(a, la, line);
		else if (line[1] == 'b' || line[2] == 'b')
			x = ft_b(b, lb, line);
		else if (ft_strcmp(line, "ss") == 0)
			x = ft_ss(a, la, b, lb);
		else if (ft_strcmp(line, "rr") == 0)
			x = ft_rr(a, la, b, lb);
		else if (ft_strcmp(line, "rrr") == 0)
			x = ft_rrr(a, la, b, lb);
		ft_strdel(&line);
	}
	free(b);
	return (lb > 0 ? -1 : x);
}

int		process_stack(char **argv, int argc)
{
	int *a;
	int *b;
	int r;
	int x;

	a = (int*)malloc(sizeof(int) * argc);
	b = (int*)malloc(sizeof(int) * argc);
	if (set_a(a, argv,  argc) && (r = ft_exec(a, b, argc, 1)) != 0)
	{
		if (is_sorted(a, argc) && r == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		x = 1;
	}
	else
		x = 0;
	free(a);
	return (x);
}

int	main(int argc, char **argv)
{
	if ((argc = count_arg(argc, argv)) == 1)
		return (0);
	if (process_stack(argv, argc))
		return (0);
	write(2, "Error\n", 6);
	return (0);
}
