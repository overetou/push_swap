#include <stdio.h>

short	is_sorted(int *a, int argc)
{
	int x;

	x = 1;
	while (x != argc)
	{
		if (a[x - 1] > a[x])
			return (0);
		x++;
	}
	return (1);
}

