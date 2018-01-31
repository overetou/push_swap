#include <unistd.h>
#include "../libft/libft.h"
#include <stdlib.h>

int		is_sorted(int *a, int argc)
{
	int x;
	int new;
	int old;

	x = 1;
	old = a[0];
	while (x != argc)
	{
		new = a[x];
		if (old > new )
			return (0);
		old = new;
		x++;
	}
	return (1);
}

int		only_int(char **argv, int argc)
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

int		ft_exec(int *a, int *b)
{
	int r;
	char *line;

	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "sa") == 0)
			ft_swap_i(&a[0], &a[1]);
		else if(ft_strcmp(line, "sb") == 0)
			ft_swap_i(&b[0], &b[1]);
		else if (ft_strcmp(line, "ss") == 0)
		{
			ft_swap_i(&b[0], &b[1]);
			ft_swap_i(&a[0], &a[1]);
		}

		ft_strdel(&line);
	}
	return (1);
}

int		process_stack(char **argv,int argc)
{
	int *a;
	int *b;
	int x;

	a = (int*)malloc(sizeof(int) * argc);
	b = (int*)malloc(sizeof(int) * argc);
	x = 0;
	while (x != argc)
	{
		a[x] = ft_atoi(argv[x + 1]);
		b[x++] = 0;
	}
	if (ft_exec(a, b))
	{
		if (is_sorted(a, argc))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		x = 1;
	}
	else
		x = 0;
	free(a);
	free(b);
	return (x);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (only_int(argv, argc))
	{
		if (process_stack(argv, argc - 1))
		return (0);
	}
	write(2, "Error\n", 6);
	return (0);
}

