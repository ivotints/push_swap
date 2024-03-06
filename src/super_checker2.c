/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_checker2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:09:53 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/16 19:15:59 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_strings_cheker(char *argv)
{
	int	count;

	count = 0;
	while (*argv)
	{
		while (*argv && *argv == ' ')
			argv++;
		if (*argv)
			count++;
		while (*argv && *argv != ' ')
			argv++;
	}
	return (count);
}

int	strlen_check(char const *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

char	*ft_word_cheker(char const *str)
{
	int		len_word;
	int		i;
	char	*word;

	len_word = strlen_check(str);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_cheker(char *str)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *) * (count_strings_cheker(str) + 1));
	if (!strings)
		return (NULL);
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (*str)
		{
			strings[i] = ft_word_cheker(str);
			i++;
		}
		while (*str && *str != ' ')
			str++;
	}
	strings[i] = 0;
	return (strings);
}

void	error_cheker(char *argv)
{
	free(argv);
	write(1, "Error\n", 6);
	exit (1);
}
