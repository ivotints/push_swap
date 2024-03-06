/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:20 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/15 18:58:26 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stk *stk)
{
	int	tmp;

	if (stk->size_a < 2)
		return ;
	tmp = stk->a[0];
	stk->a[0] = stk->a[1];
	stk->a[1] = tmp;
	ft_printf("sa\n");
}

void	sb(t_stk *stk)
{
	int	tmp;

	if (stk->size_b < 2)
		return ;
	tmp = stk->b[0];
	stk->b[0] = stk->b[1];
	stk->b[1] = tmp;
	ft_printf("sb\n");
}

//a: 10 40 20 80	b: 60 70
//a: 40 20 80		b: 10 60 70

void	pb(t_stk *stk)
{
	int	i;

	if (stk->size_a)
	{
		stk->size_b++;
		i = stk->size_b;
		while (--i > 0)
			stk->b[i] = stk->b[i - 1];
		stk->b[0] = stk->a[0];
		i = -1;
		stk->size_a--;
		while (++i < stk->size_a)
			stk->a[i] = stk->a[i + 1];
		ft_printf("pb\n");
	}
}

void	pa(t_stk *stk)
{
	int	i;

	if (stk->size_b)
	{
		stk->size_a++;
		i = stk->size_a;
		while (--i > 0)
			stk->a[i] = stk->a[i - 1];
		stk->a[0] = stk->b[0];
		i = -1;
		stk->size_b--;
		while (++i < stk->size_b)
			stk->b[i] = stk->b[i + 1];
		ft_printf("pa\n");
	}
}

int	ft_push(t_stk *stk, int size, int push)
{
	if (push == 0)
		pb(stk);
	else
		pa(stk);
	size--;
	return (size);
}
