#include <unistd.h>
#include "libft.h"
#include <stdio.h>

bool is_sorted(char **argv, int argc)
{
	int x;
	int new;
	int old;

	x = 1;
	old = ft_atoi(argv[0]);
	while (x != argc)
	{
		new = ft_atoi(argv[x]);
		if (old > new )
			return (0);
		old = new;
		x++;
	}
	return (1);
}

bool only_int(char **argv, int argc)
{
	int x;

	x = 1;
	while (argc > x)
	{
		if (ft_strcmp(ft_itoa(ft_atoi(argv[x])), argv[x]) != 0)
			return (0);
		x++;
	}
	return (1);
}

get_stack(argv, argc)
{
	int *a;
	int *b;
	int x;

	a = (int*)malloc(sizeof(int) * argc - 1);
	b = (int*)malloc(sizeof(int) * argc - 1);
	x = 1;
	while (x != argc)
		a[x - 1] = ft_atoi(argv[x++]);
	ft_exec(a, b);
	free(b);
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a);
}
//int	main(int argc, char **argv)
//{
//	if (argc == 1)
//		return (0);
//	if (only_int(argv, argc) && stack(argv, argc))
//	{
//		if (is_sorted(argvi, argc))
//			write(1, "OK\n", 3);
//		else
//			write(1, "KO\n", 3);
//	}
//	else
//		write(2, "Error\n", 6);
//	return (0);
//}

int	main(int argc, char **argv)
{
	
	return (0);
}


