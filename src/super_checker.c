/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:17:36 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/16 19:25:19 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// return 0 if ERROR

void	ft_check_chars(char *argv)
{
	int	i;

	i = 0;
	if (!(argv[i]))
		error_cheker(argv);
	while (argv[i])
	{
		if (!((argv[i] >= '0' && argv[i] <= '9')
				|| argv[i] == ' ' || argv[i] == '-' || argv[i] == '+'))
			error_cheker(argv);
		i++;
	}
	return ;
}

void	ft_check_max_min_int(char *argv, int count_words)
{
	int		i;
	char	**string;
	int		*a;

	i = 0;
	a = (int *)malloc(count_words * sizeof(int));
	string = ft_split_cheker(argv);
	while (string[i])
	{
		a[i] = ft_atoi_cheker_cheker(string, i, a, argv);
		i++;
	}
	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
	double_check_2(a, count_words, argv);
	free(a);
}

// return 0 if ERROR

int	ft_super_checker(int argc, char *argv)
{
	int	count_words;

	if (argc == 2)
	{
		ft_check_chars(argv);
		count_words = count_strings_cheker(argv);
		if (count_words == 0)
			error_cheker(argv);
		ft_check_max_min_int(argv, count_words);
		if (count_words == 1)
		{
			free(argv);
			exit (0);
		}
	}
	return (1);
}

void	ft_error_atoi_cheker(char **str, int *a, char *argv)
{
	int	i;

	i = 0;
	free(argv);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	free(a);
	write(1, "Error\n", 6);
	exit (1);
	return ;
}

int	ft_atoi_cheker_cheker(char **str, int j, int *a, char *argv)
{
	unsigned int		i;
	int					sign;
	unsigned long int	res;

	i = 0;
	sign = 1;
	if (str[j][i] == '-' || str[j][i] == '+')
		if (str[j][i++] == '-')
			sign = -1;
	if (str[j][i] == '-' || str[j][i] == '+' || strlen_check(&str[j][i]) > 14
			|| !str[j][i])
		ft_error_atoi_cheker(str, a, argv);
	res = 0;
	while (str[j][i] >= '0' && str[j][i] <= '9' && str[j][i])
	{
		res = (res * 10) + (str[j][i] - '0');
		i++;
	}
	if (str[j][i] != 0)
		ft_error_atoi_cheker(str, a, argv);
	if ((res > 2147483648 && sign == -1) || (res > 2147483647 && sign == 1))
		ft_error_atoi_cheker(str, a, argv);
	return (res * sign);
}
