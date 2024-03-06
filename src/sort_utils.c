/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:14 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/15 18:59:46 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	case3b(t_stk *stk, int len)
{
	if (len == 1)
		pa(stk);
	else if (len == 2)
	{
		if (stk->b[0] < stk->b[1])
			sb(stk);
		while (len--)
			pa(stk);
	}
	else if (len == 3)
	{
		while (len || !(stk->a[0] < stk->a[1] && stk->a[1] < stk->a[2]))
		{
			if (len == 1 && stk->a[0] > stk->a[1])
				sa(stk);
			else if (len == 1 || (len >= 2 && stk->b[0] > stk->b[1])
				|| (len == 3 && stk ->b[0] > stk->b[2]))
				len = ft_push(stk, len, 1);
			else
				sb(stk);
		}
	}
	return (0);
}

void	sort_case3(t_stk *stk, int l)
{
	if (l == 3 && stk->size_a == 3)
		ft_case3(stk);
	else if (l == 2)
	{
		if (stk->a[0] > stk->a[1])
			sa(stk);
	}
	else if (l == 3)
	{
		while (l != 3 || !(stk->a[0] < stk->a[1] && stk->a[1] < stk->a[2]))
		{
			if (l == 3 && stk->a[0] > stk->a[1] && stk->a[2])
				sa(stk);
			else if (l == 3 && !(stk->a[2] > stk->a[0]
					&& stk->a[2] > stk->a[1]))
				l = ft_push(stk, l, 0);
			else if (stk->a[0] > stk->a[1])
				sa(stk);
			else if (l++)
				pa(stk);
		}
	}
}

// 1 2 3  middle is 2
// 1 2 3 4 middle is 2

int	midval(int *middle, int *stk, int size)
{
	int	*temp_stk;
	int	i;

	temp_stk = (int *)malloc(size * sizeof(int));
	if (!temp_stk)
		return (0);
	i = 0;
	while (i < size)
	{
		temp_stk[i] = stk[i];
		i++;
	}
	bubble_sort(temp_stk, size);
	*middle = temp_stk[size / 2];
	free(temp_stk);
	return (1);
}

void	bubble_sort(int *stk_temp, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stk_temp[i] > stk_temp[j])
			{
				temp = stk_temp[i];
				stk_temp[i] = stk_temp[j];
				stk_temp[j] = temp;
			}
			j++;
		}
		i++;
	}
}

// 40 20 50
// 40 20 10
// 40 20 30
// 40 60 50
// 40 50 30

void	ft_case3(t_stk *case3)
{
	if (case3->a[2] > case3->a[0] && case3->a[0] > case3->a[1])
		sa(case3);
	if (case3->a[0] > case3->a[1] && case3->a[1] > case3->a[2])
	{
		sa(case3);
		rra(case3);
	}
	if (case3->a[0] > case3->a[2] && case3->a[2] > case3->a[1])
		ra(case3);
	if (case3->a[1] > case3->a[2] && case3->a[2] > case3->a[0])
	{
		rra(case3);
		sa(case3);
	}
	if (case3->a[1] > case3->a[0] && case3->a[0] > case3->a[2])
		rra(case3);
}
