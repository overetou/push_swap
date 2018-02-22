/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:11:42 by overetou          #+#    #+#             */
/*   Updated: 2018/02/22 21:14:17 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>

typedef struct	s_pile
{
	int 			n;
	short			stop;
	struct s_pile	*next;
}				t_pile;

short	ft_sx(int *x, int lx);
short	ft_px(int *less, int *lless, int *more, int *lmore);
void 	dsp_stack(int *a, int la, int *b, int lb);
short	ft_rx(int *x, int lx);
short	ft_ss(int *a, int la, int *b, int lb);
short	ft_rrx(int *x, int lx);
short	ft_a(int *a, int la, char *line);
short	ft_b(int *b, int lb, char *line);
short	ft_rr(int *a, int la, int *b, int lb);
short	ft_rrr(int *a, int la, int *b, int lb);
int		only_int(char **argv, int argc);
int		solve(int *a, int *b, int la, int lb);
void	quick(int *a, int la, int *pb);
short	is_sorted_r(int *b, int lb);
void	sx(t_pile *x);
void	rx(t_pile **x);
void	rrx(t_pile **x);
void	px(t_pile **less, t_pile **more);
void	ss(t_pile *a, t_pile *b);
short	sorted(t_pile *a);
void	dsp(t_pile *a, t_pile *b);
short	sorted(t_pile *a);
void	empty_a(t_pile **a, t_pile **b);

#endif
