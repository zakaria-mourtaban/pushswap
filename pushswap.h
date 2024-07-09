/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:21:19 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/09 15:20:45 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

void		fillstack(t_list *stacka, int *nums, int size);
void		printlist(t_list *node);
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
void		sa(t_list *stacka);
void		sb(t_list *stackb);
void		ss(t_list *stacka, t_list *stackb);
void		pa(t_list *stacka, t_list *stackb);
void		pb(t_list *stacka, t_list *stackb);
void		rra(t_list *stacka);
void		rrb(t_list *stackb);
void		rrr(t_list *stacka, t_list *stackb);
void		ra(t_list *stacka);
void		rb(t_list *stackb);
void		rr(t_list *stacka, t_list *stackb);
#endif