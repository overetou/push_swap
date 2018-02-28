/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:11:42 by overetou          #+#    #+#             */
/*   Updated: 2018/02/28 17:37:04 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>

typedef struct	s_pile
{
	int 		n;
	short		stop;
	struct s_pile	*next;
}		t_pile;

typedef	struct	s_instr
{
	char	*word;
	struct s_instr	*next;
}		t_instr;

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
int		only_int(char *s);
int		solve(int *a, int *b, int la, int lb);
void	quick(int *a, int la, int *pb);
short	is_sorted_r(int *b, int lb);
t_instr	*sx(t_pile *x, char c, t_instr *itr);
t_instr *rx(t_pile **x, char c, t_instr *itr);
t_instr *rrx(t_pile **x, char c, t_instr *itr);
t_instr *px(t_pile **less, t_pile **more, char c, t_instr *itr);
short	sorted(t_pile *a);
void	dsp(t_pile *a, t_pile *b);
short	sorted(t_pile *a);
t_instr	*empty_a(t_pile **a, t_pile **b, t_instr *itr);
void	move_b(t_pile **a, t_pile **b, t_instr *itr);
void	move_a(t_pile **a, t_pile **b, t_instr *itr);
int		get_median(t_pile *a);
void	shake_sort(t_pile **a, int size);
t_instr	*add_instr(char *s, t_instr *old);
void	rm_instr(t_instr **instr);
void	process_instr(t_instr *my_itr);
void	pre_process_b(t_instr *itr);
void	pre_process_a(t_instr *itr);
int		count_arg(int argc, char **argv);
short	set_a(int *a, char **argv, int argc);

#endif
