/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-11 15:03:16 by ysuliman          #+#    #+#             */
/*   Updated: 2024-11-11 15:03:16 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(long *a)
{
	int		len;
	long	top;

	len = ft_intlen(a) - 1;
	if (len < 1)
		return ;
	top = a[len];
	while (len > 0)
	{
		a[len] = a[len - 1];
		len--;
	}
	a[0] = top;
	write(1, "ra\n", 3);
}

void	rb(long *b)
{
	int		len;
	long	top;

	len = ft_intlen(b) - 1;
	if (len < 1)
		return ;
	top = b[len];
	while (len > 0)
	{
		b[len] = b[len - 1];
		len--;
	}
	b[0] = top;
	write(1, "rb\n", 3);
}

void	rr(long *a, long *b)
{
	int		len;
	long	top;

	len = ft_intlen(a) - 1;
	if (len < 1)
		return ;
	top = a[len];
	while (len > 0)
	{
		a[len] = a[len - 1];
		len--;
	}
	a[0] = top;
	len = ft_intlen(b) - 1;
	if (len < 1)
		return ;
	top = b[len];
	while (len > 0)
	{
		b[len] = b[len - 1];
		len--;
	}
	b[0] = top;
	write(1, "rr\n", 3);
}
