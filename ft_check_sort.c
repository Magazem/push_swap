/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:14:14 by ysuliman          #+#    #+#             */
/*   Updated: 2024/11/10 17:10:48 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_check_sort(long *a)
{
	int		i;
	long	tmp;

	i = 1;
	tmp = a[0];
	if (ft_intlen(a) < 2)
		return (1);
	while (a[i] != '\0')
	{
		if (tmp < a[i])
			return (0);
		tmp = a[i];
		i++;
	}
	return (1);
}
