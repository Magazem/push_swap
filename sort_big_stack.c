/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:49:23 by ysuliman          #+#    #+#             */
/*   Updated: 2024/11/05 14:08:30 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remorph(long *weight, long *index, int a_len)
{
	long	num_index;
	int		i;

	i = 0;
	weight[a_len] = 0;
	while (i < a_len)
	{
		num_index = index[a_len - i - 1];
		weight[num_index - 1] = a_len - i;
		i++;
	}
}

int	bits_num(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count += 1;
		n = n >> 1;
	}
	return (count);
}

void	bubble_sort(long *morph, int a_len, long *index)
{
	long	temp;
	int		i;
	int		j;

	i = 0;
	while (i < a_len - 1)
	{
		j = 0;
		while (j < a_len - i - 1)
		{
			if (morph[j] > morph[j + 1])
			{
				temp = morph[j];
				morph[j] = morph[j + 1];
				morph[j + 1] = temp;
				temp = index[j];
				index[j] = index[j + 1];
				index[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	bit_sort(long *a, long *b, int a_len)
{
	int	maximum_bits;
	int	i;
	int	j;
	int	num_zeros;

	i = -1;
	maximum_bits = bits_num(a_len);
	while (++i < maximum_bits)
	{
		j = -1;
		num_zeros = 0;
		while (++j < a_len)
		{
			if (((a[ft_intlen(a) - 1] >> i) & 1) == 1)
				ra(a);
			else
			{
				pb(a, b);
				num_zeros++;
			}
		}
		while (num_zeros-- > 0)
			pa(a, b);
	}
}

void	sort_big_stack(long *a, long *b, int a_len)
{
	int		i;
	long	*weight;
	long	*index;

	index = malloc(sizeof(long) * a_len);
	weight = malloc(sizeof(long) * a_len);
	i = 0;
	while (i < a_len)
	{
		index[i] = i + 1;
		i++;
	}
	bubble_sort(a, a_len, index);
	remorph(weight, index, a_len);
	bit_sort(weight, b, a_len);
	free(weight);
	free(index);
}
