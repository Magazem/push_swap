/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:51:41 by ysuliman          #+#    #+#             */
/*   Updated: 2024/11/10 21:54:06 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_smallest_int(long *array, int len)
{
	long	smallest;

	smallest = 1;
	while (len > 0)
	{
		if (array[len - 1] < smallest)
			smallest = array[len - 1];
		len--;
	}
	return (smallest);
}

void	restack(long *array, int ac)
{
	int		i;
	long	smallest;
	int		len;

	len = ac - 1;
	smallest = find_smallest_int(array, len);
	i = -1;
	if (smallest <= 0)
	{
		while (++i < len)
			array[i] = array[i] - smallest + 1;
	}
}

long	*ft_stacker(int ac, char **av, int flag)
{
	long	*stack;
	int		i;
	long	num;
	int		n;

	stack = malloc(sizeof(long) * (ac));
	i = ac - 2;
	n = 0;
	while (i >= 0)
	{
		if (!ft_isdigit_str(av[n]))
			arg_error(stack, av, flag);
		num = ft_atol(av[n++]);
		if (num > 2147483647 || num < -2147483648)
			arg_error(stack, av, flag);
		stack[i] = (long)num;
		i--;
	}
	stack[ac - 1] = '\0';
	if (ft_check_duplicate(stack, ac - 1))
		arg_error(stack, av, flag);
	restack(stack, ac);
	return (stack);
}

long	*ft_process(int ac, char **av, int flag)
{
	int	i;

	i = 0;
	if (flag)
	{
		while (av[i])
		{
			av[i - 1] = av[i];
			i++;
		}
	}
	if (ac >= 2)
		return (ft_stacker(ac, av, flag));
	return (NULL);
}

int	main(int ac, char **av)
{
	long	*a;
	long	*b;
	int		flag;

	if (ac < 2)
		return (0);
	flag = 1;
	if (ac == 2)
	{
		ac = countspaces(av[1]) + 2;
		av = ft_split(av[1], 32);
		flag = 0;
	}
	a = ft_process(ac, av, flag);
	b = malloc(sizeof(long) * (ac - 1));
	ft_bzero(b, ac - 1);
	if (a && !ft_check_sort(a))
		ft_sort(a, b);
	if (!flag)
		split_free(av);
	free(a);
	free(b);
	return (0);
}
