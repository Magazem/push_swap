/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-11 15:08:54 by ysuliman          #+#    #+#             */
/*   Updated: 2024-11-11 15:08:54 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(long *a)
{
	int		len;
	int		i;
	long	bottom;

	len = ft_intlen(a) - 1;
	if (len < 1)
		return ;
	bottom = a[0];
	i = 0;
	while (i < len)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[len] = bottom;
	write(1, "rra\n", 4);
}

void	rrb(long *b)
{
	int		len;
	int		i;
	long	bottom;

	len = ft_intlen(b) - 1;
	if (len < 1)
		return ;
	bottom = b[0];
	i = 0;
	while (i < len)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[len] = bottom;
	write(1, "rrb\n", 4);
}

void	rrr(long *a, long *b)
{
	int		len;
	int		i;
	long	bottom;

	len = ft_intlen(b) - 1;
	bottom = b[0];
	i = 0;
	while (i < len)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[len] = bottom;
	len = ft_intlen(a) - 1;
	if (len < 1)
		return ;
	bottom = a[0];
	i = 0;
	while (i < len)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[len] = bottom;
	write(1, "rrr\n", 4);
}
