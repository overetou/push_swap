/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:11:42 by overetou          #+#    #+#             */
/*   Updated: 2018/02/14 12:52:13 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

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
int	only_int(char **argv, int argc);
int		solve(int *a, int *b, int la, int lb);
void	choose(int *a, int *b, int la);
void	pivot(int *a, int *b, int la, int lb);
short	test_s(int *a, int la, int *b, int lb);
void	go_to_target(int target, int *a, int la);
int		find_next(int *a, int la, int *index);
int		get_ind(int n, int *ind);

#endif
