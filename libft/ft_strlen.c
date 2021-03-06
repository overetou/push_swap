/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:14:44 by overetou          #+#    #+#             */
/*   Updated: 2018/01/21 15:42:47 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s)
{
	unsigned int x;

	if (!s)
		return (0);
	x = 0;
	while (s[x])
		x++;
	return (x);
}
