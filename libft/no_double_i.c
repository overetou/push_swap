/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_double_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:36:40 by overetou          #+#    #+#             */
/*   Updated: 2018/02/06 16:53:50 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short	no_double_i(int *a, int length)
{
	int x;
	int y;
	int n;

	x = 0;
	while (x != length)
	{
		n = 0;
		y = 0;
		while (y != length)
		{
			if (a[x] == a[y++])
				n++;
		}
		if (n != 1)
			return (0);
		x++;
	}
	return (1);
}

