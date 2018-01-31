/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:42:52 by overetou          #+#    #+#             */
/*   Updated: 2018/01/31 16:38:37 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_pile(char **line, char *cpy)
{
	int		x;
	char	part[BUFF_SIZE + 1];
	char	*to_delete;
	int		y;

	x = 0;
	y = 0;
	while (cpy[x] != '\n' && cpy[x])
		x++;
	while (y < x)
	{
		part[y] = cpy[y];
		y++;
	}
	part[y] = '\0';
	to_delete = *line;
	if (!(*line = ft_strjoin(*line, part)))
		return (-1);
	ft_strdel(&to_delete);
	return (y);
}

int	ft_build_line(char *cpy, char **line, int y, int fd)
{
	int rvalue;
	int x;

	if (!(*line = ft_strnew(0)))
		return (-1);
	while (cpy[y] != '\n')
	{
		if ((x = ft_pile(line, cpy + y)) == -1)
			return (-1);
		y += x;
		if (!cpy[y])
		{
			ft_bzero(cpy, BUFF_SIZE);
			rvalue = read(fd, cpy, BUFF_SIZE);
			y = 0;
			if (!rvalue)
				return (0);
			if (*cpy == '\n')
				return (0);
		}
	}
	return (y);
}

int	gnl_simple(const int fd, char **line, char *cpy)
{
	int				y;
	size_t			i;

	if (!(cpy[0]))
	{
		ft_bzero(cpy, BUFF_SIZE);
		y = read(fd, cpy, BUFF_SIZE);
		if (y == -1 || !y)
			return (y);
		y = 0;
	}
	else
	{
		y = ft_strchr(cpy, 'X') - cpy;
		cpy[y++] = '.';
	}
	if ((y = ft_build_line(cpy, line, y, fd)) == -1)
		return (-1);
	i = 0;
	while (y--)
		cpy[i++] = '.';
	cpy[i] = 'X';
	i + 1 == ft_strlen(cpy) ? cpy[0] = '\0' : (void)i;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*master;
	t_list			*head;

	head = master;
	while (head)
	{
		if ((int)head->content_size == fd)
			return (gnl_simple((int)head->content_size, line, head->content));
		head = head->next;
	}
	head = ft_lstnew(NULL, 0);
	head->content_size = (size_t)fd;
	head->content = ft_strnew(BUFF_SIZE);
	ft_lstadd(&master, head);
	head = master;
	return (gnl_simple(fd, line, head->content));
}
