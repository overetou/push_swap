/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:11:42 by overetou          #+#    #+#             */
/*   Updated: 2018/02/05 15:16:47 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

short ft_sx(int *x, int lx);
short ft_px(int *a, int *la, int *b, int *lb);
void  dsp_stack(int *a, int *b, int la, int lb);
short ft_rx(int *x, int lx);
short ft_ss(int *a, int la, int *b, int lb);
short ft_rrx(int *x, int lx);
short ft_a(int *a, int la, char *line);
short ft_b(int *b, int lb, char *line);
short ft_rr(int *a, int la, int *b, int lb);
short ft_rrr(int *a, int la, int *b, int lb);

#endif
