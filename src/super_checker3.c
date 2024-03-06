/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_checker3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:26:10 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/16 21:08:43 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	double_check_2(int *stk1, int size, char *argv)
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
			{
				free(stk1);
				free(argv);
				write(1, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

char	*ft_strjoins(int argc, char **argv, int i, int a)
{
	char	*str;
	int		j;
	int		tot_len;

	tot_len = 0;
	while (i < argc)
		tot_len += ft_strlen(argv[i++]);
	str = (char *)malloc(tot_len * sizeof(char) + argc);
	i = 0;
	while (a < argc)
	{
		j = 0;
		while (argv[a][j])
		{
			str[i] = argv[a][j];
			i++;
			j++;
		}
		if (++a < argc)
			str[i++] = ' ';
	}
	str[i] = '\0';
	return (str);
}
