/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:43:40 by ysuliman          #+#    #+#             */
/*   Updated: 2024/11/10 19:48:52 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_ra(long *a, long *b)
{
	pa(a, b);
	ra(a);
}

void	double_ra(long *a)
{
	ra(a);
	ra(a);
}

void	first_stack(long *a, long *b, int top_a, int top_b)
{
	if (b[top_b] < a[top_a])
		pa(a, b);
	else if ((b[top_b] > a[top_a]) && (b[top_b] < a[top_a - 1]))
	{
		ra(a);
		pa(a, b);
		rra(a);
	}
	else if ((b[top_b] > a[top_a - 1]) && (b[top_b] < a[top_a - 2]))
	{
		rra(a);
		pa(a, b);
		rra(a);
		rra(a);
	}
	else if (b[top_b] > a[top_a - 2])
	{
		pa(a, b);
		ra(a);
	}
}

void	second_stack(long *a, long *b, int top_a, int top_b)
{
	if (b[top_b] < a[top_a])
		pa(a, b);
	else if ((b[top_b] > a[top_a]) && (b[top_b] < a[top_a - 1]))
	{
		ra(a);
		pa(a, b);
		rra(a);
	}
	else if ((b[top_b] > a[top_a - 1]) && (b[top_b] < a[top_a - 2]))
	{
		ra(a);
		pa(a, b);
		sa(a);
		rra(a);
	}
	else if ((b[top_b] > a[top_a - 2]) && (b[top_b] < a[top_a - 3]))
	{
		rra(a);
		pa(a, b);
		double_ra(a);
	}
	else if (b[top_b] > a[top_a - 3])
		pa_ra(a, b);
}

void	sort_5(long *a, long *b)
{
	pb(a, b);
	pb(a, b);
	sort_3(a);
	while (b[0] != 0)
	{
		if (ft_intlen(a) == 3)
			first_stack(a, b, ft_intlen(a) - 1, ft_intlen(b) - 1);
		else if (ft_intlen(a) == 4)
			second_stack(a, b, ft_intlen(a) - 1, ft_intlen(b) - 1);
	}
}
