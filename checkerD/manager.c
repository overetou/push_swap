#include "checker.h"

short ft_a(int *a, int la, char *line)
{
  if (ft_strcmp(line, "sa") == 0)
    ft_sx(a, la);
  else if (ft_strcmp(line, "ra") == 0)
    ft_rx(a, la);
  else if (ft_strcmp(line, "rra") == 0)
		ft_rrx(a, la);
  else
    return (0);
  return (1);
}

short ft_b(int *b, int lb, char *line)
{
  if (ft_strcmp(line, "sb") == 0)
    ft_sx(b, lb);
  else if (ft_strcmp(line, "rb") == 0)
    ft_rx(b, lb);
  else if (ft_strcmp(line, "rrb") == 0)
		ft_rrx(b, lb);
  else
    return (0);
  return (1);
}

short ft_ss(int *a, int la, int *b, int lb)
{
  ft_sx(a, la);
  ft_sx(b, lb);
  return (1);
}

short ft_rr(int *a, int la, int *b, int lb)
{
    ft_rx(a, la);
    ft_rx(b, lb);
    return (1);
}

short ft_rrr(int *a, int la, int *b, int lb)
{
    ft_rrx(a, la);
    ft_rrx(b, lb);
    return (1);
}
