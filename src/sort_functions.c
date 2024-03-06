/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:32 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/16 16:24:48 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(int *stk1, int *stk2, char *argv[])
{
	int	i;

	free(stk1);
	free(stk2);
	i = 0;
	while (argv && argv[i])
		free(argv[i++]);
	free(argv);
	write(2, "Error\n", 6);
	exit (1);
}

//fail with 18446744073709551616 (overflow) (FIXED WITH FT_STRLEN)

int	safe_atoi(char *str)
{
	unsigned int		i;
	int					sign;
	unsigned long int	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-' || str [i] == '+')
		if (str[i++] == '-')
			sign = -1;
	res = 0;
	while (str[i])
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * sign);
}

int	arrlen(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

//order 0 == ascending

int	sort_check(int *stk, int size, int order)
{
	int	i;

	i = 1;
	if (order == 0)
	{
		while (i < size)
		{
			if (stk[i - 1] > stk[i])
				return (0);
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			if (stk[i - 1] < stk[i])
				return (0);
			i++;
		}
	}
	return (1);
}

void	double_check(int *stk1, int *stk2, int size, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stk1[i] == stk1[j])
				ft_error(stk1, stk2, argv);
			j++;
		}
		i++;
	}
}
