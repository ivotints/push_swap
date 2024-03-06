/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:15:14 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/16 20:42:38 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf.h"

typedef struct s_stk
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stk;

void	pb(t_stk *stk);
void	pa(t_stk *stk);
void	ra(t_stk *stk);
void	rb(t_stk *stk);
void	rra(t_stk *stk);
void	rrb(t_stk *stk);
void	sa(t_stk *stk);
void	sb(t_stk *stk);
void	push_swap(char *argv[]);
int		case3b(t_stk *stk, int len);
void	sort_case3(t_stk *stk, int l);
int		midval(int *middle, int *stk, int size);
int		sort_a(t_stk *stk, int size, int count_r);
int		sort_b(t_stk *stk, int size, int rotations);
void	bubble_sort(int *stk_temp, int size);
void	ft_case3(t_stk *case3);
int		ft_sort(t_stk *stk, int size);
int		ft_push(t_stk *stk, int len, int push);
void	ft_error(int *stk1, int *stk2, char *argv[]);
int		safe_atoi(char *str);
int		arrlen(char **av);
int		sort_check(int *stk, int size, int order);
void	double_check(int *stk1, int *stk2, int size, char *argv[]);
char	**ft_split(char *str, char c);
int		ft_strlen(char *s);
//main
char	*ft_strjoins(int argc, char **argv, int i, int a);
//super checker
void	ft_check_chars(char *argv);
void	ft_check_max_min_int(char *argv, int count_words);
int		ft_super_checker(int argc, char *argv);
void	ft_error_atoi_cheker(char **str, int *a, char *argv);
int		ft_atoi_cheker_cheker(char **str, int j, int *a, char *argv);
int		count_strings_cheker(char *argv);
int		strlen_check(char const *str);
char	*ft_word_cheker(char const *str);
char	**ft_split_cheker(char *str);
void	error_cheker(char *argv);
void	double_check_2(int *stk1, int size, char *argv);

#endif
