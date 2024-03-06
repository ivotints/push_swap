/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:42 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/16 21:08:53 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_b(t_stk *stk, int size, int rotations)
{
	int	middle;
	int	val;

	if (sort_check(stk->b, size, 1) == 1)
		while (size--)
			pa(stk);
	if (size <= 3)
	{
		case3b(stk, size);
		return (1);
	}
	if (!midval(&middle, stk->b, size))
		return (0);
	val = size;
	while (size != val / 2)
	{
		if (stk->b[0] >= middle && size--)
			pa(stk);
		else if (++rotations)
			rb(stk);
	}
	while (val / 2 != stk->size_b && rotations--)
		rrb(stk);
	return (sort_a(stk, val / 2 + val % 2, 0)
		&& sort_b(stk, val / 2, 0));
}

int	sort_a(t_stk *stk, int size, int rotations)
{
	int	middle;
	int	val;

	if (sort_check(stk->a, size, 0) == 1)
		return (1);
	if (size <= 3)
	{
		sort_case3(stk, size);
		return (1);
	}
	if (!midval(&middle, stk->a, size))
		return (0);
	val = size;
	while (size != val / 2 + val % 2)
	{
		if (stk->a[0] < middle && (size--))
			pb(stk);
		else if (++rotations)
			ra(stk);
	}
	while (val / 2 + val % 2 != stk->size_a && rotations--)
		rra(stk);
	return (sort_a(stk, val / 2 + val % 2, 0) && sort_b(stk, val / 2, 0));
}

int	ft_sort(t_stk *stk, int size)
{
	if (sort_check(stk->a, stk->size_a, 0) == 0)
	{
		if (size == 2)
			sa(stk);
		else if (size == 3)
			ft_case3(stk);
		else
			if (!sort_a(stk, size, 0))
				ft_error(stk->a, stk->b, 0);
	}
	return (0);
}

void	push_swap(char *argv[])
{
	t_stk	stk;
	int		i;

	stk.size_a = arrlen(argv);
	stk.a = (int *)malloc(stk.size_a * sizeof(int));
	if (!stk.a)
		return ;
	stk.b = (int *)malloc(stk.size_a * sizeof(int));
	if (!stk.b)
	{
		free(stk.a);
		return ;
	}
	stk.size_b = 0;
	i = -1;
	while (++i < stk.size_a)
		stk.a[i] = safe_atoi(argv[i]);
	ft_sort(&stk, stk.size_a);
	free(stk.a);
	free(stk.b);
}

int	main(int argc, char *argv[])
{
	char	**string;
	char	*str;
	int		i;

	if (argc > 1)
	{
		argv++;
		str = ft_strjoins(argc - 1, argv, 0, 0);
		ft_super_checker(2, str);
		string = ft_split(str, ' ');
		push_swap(string);
		free(str);
		i = 0;
		while (string[i])
		{
			free(string[i]);
			i++;
		}
		free(string);
	}
	return (0);
}
