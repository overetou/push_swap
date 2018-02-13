#include <unistd.h>
#include <stdlib.h>
#include <push_swap.h>

void	empty_b(int *a, int *la, int *b, int *lb)
{
	while (*lb)
	{
		write(0, "pa\n", 3);
		ft_px(b, lb, a, la);
	}
}

int		*dirty_sort(int *a, int la, int *b, int lb)
{
	int *index;
	int i;

	i = 0;
	index = (int*)malloc(sizeof(int) * la + 1);
	while (i != la)
	{
		index[i] = a[i];
		i++;
	}
	solve(index, b, la, lb);
	return (index);
}

short	wheel_ok(int *a, int la)
{
	int i;
	int n;

	i = 1;
	n = 0;
	if (a[0] > a[la - 1])
		n++;
	while (i != la)
	{
		if (a[i] > a[i - 1])
			n++;
		i++;
	}
	if (n != la - 1)
		return (0);
	return (1);
}

void	spin_til_ok(int *a, int la)
{
	int i;
	
	if (is_sorted(a, la--))
			return ;
	i = 1;
	while (a[i] > a[i - 1])
		i++;
	if (i > la++ / 2)
	{
		while (i++ != la)
		{
			write(0, "rra\n", 4);
			ft_rrx(a, la);
		}
	}
	else
	{
		while (i--)
		{
			write(0, "ra\n", 3);
			ft_rx(a, la);
		}
	}
}

void	pivot(int *a, int *b, int la, int lb)
{
	int *index;
	int target;

	index = dirty_sort(a, la, b, lb);
	target = a[1];
//	while (!wheel_ok(a, la))
//	{
//		if (!target_ok(target, a, la, index))
//		{
//			target = find_next(a, la,index);
//			go_to_target(target, a, la);
//		}
//		if (!b_involved(a, &la, b, &lb))
//			move_target(target, a, la);
//	}
	//spin_til_ok(a, la);
	//empty_b(a, &la, b, &lb);
	//dsp_stack(a, la, b, lb);
}

