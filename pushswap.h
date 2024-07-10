/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:21:19 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/10 20:54:01 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

void		fillstack(t_list *stacka, int *nums, int size);
void		printlist(t_list **node);
int			dupinarr(int *nums, int size);
int			morethanint(char **vars);
int			ft_isdigitarr(char **s);
int			vartoarr(char **var, int **arr);
long long	ft_atoll(const char *str);
void		free_variables(char **variables, int *single_ptr);
void		errorandexit(char *msg);
int			issorted(t_list *stacka);
int			sorted(t_list *stacka, int *nums, int size);
void		sort(t_list *stacka, t_list *stackb, int *nums, int size);
void		fill_stacks(t_list *stacka, int *nums, int size);
void		allocate_stacks(t_list *stacka, t_list *stackb, int size);
int			sa(t_list **stack_a);
int			sb(t_list **stack_b);
int			ss(t_list **stack_a, t_list **stack_b);
int			pa(t_list **stack_a, t_list **stack_b);
int			pb(t_list **stack_a, t_list **stack_b);
int			rra(t_list **stack_a);
int			rrb(t_list **stack_b);
int			rrr(t_list **stack_a, t_list **stack_b);
int			ra(t_list **stack_a);
int			rb(t_list **stack_b);
int			rr(t_list **stack_a, t_list **stack_b);
#endif