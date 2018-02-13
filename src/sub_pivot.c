#include "push_swap.h"

short	target_ok(int target, int *a, int la, int *index)
{
	int i;

	if (target < index[la / 2 - 1])
		return (1);
	ft_putnbr(target);
	i = 0;
	while (a[i] != target)
		i++;
	if (i == la - 1)
	{
		if (target > a[0])
			return (1);
	}
	else if (target > a[i + 1])
		return (1);
	return (0);
}

void	go_to_target(int target,int *a, int la)
{
	
}


