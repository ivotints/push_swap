/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:25 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/15 20:25:55 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//40 10 20 becomes 10 20 40

void	ra(t_stk *stk)
{
	int	tmp;
	int	i;

	if (stk->size_a < 2)
		return ;
	tmp = stk->a[0];
	i = 1;
	while (i < stk->size_a)
	{
		stk->a[i - 1] = stk->a[i];
		i++;
	}
	stk->a[i - 1] = tmp;
	ft_printf("ra\n");
}

void	rb(t_stk *stk)
{
	int	tmp;
	int	i;

	if (stk->size_b < 2)
		return ;
	tmp = stk->b[0];
	i = 1;
	while (i < stk->size_b)
	{
		stk->b[i - 1] = stk->b[i];
		i++;
	}
	stk->b[i - 1] = tmp;
	ft_printf("rb\n");
}

//40 20 10 will become 10 40 20

void	rra(t_stk *stk)
{
	int	tmp;
	int	i;

	if (stk->size_a < 2)
		return ;
	i = stk->size_a - 1;
	tmp = stk->a[i];
	while (i)
	{
		stk->a[i] = stk->a[i - 1];
		i--;
	}
	stk->a[0] = tmp;
	ft_printf("rra\n");
}

void	rrb(t_stk *stk)
{
	int	tmp;
	int	i;

	if (stk->size_b < 2)
		return ;
	i = stk->size_b - 1;
	tmp = stk->b[i];
	while (i)
	{
		stk->b[i] = stk->b[i - 1];
		i--;
	}
	stk->b[0] = tmp;
	ft_printf("rrb\n");
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
