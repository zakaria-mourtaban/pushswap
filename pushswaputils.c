/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaputils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:17:30 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/10 20:10:43 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	issorted(t_list *stacka)
{
	t_list	*tmp;

	tmp = stacka;
	while (tmp->next != NULL)
	{
		if (tmp != NULL && tmp->next != NULL && tmp->content != NULL
			&& tmp->next->content != NULL)
		{
			if (*(int *)tmp->content > *(int *)tmp->next->content)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	sorted(t_list *stacka, int *nums, int size)
{
	t_list	*tmp;
	int		i;
	int		found;
	int		*dptr;

	found = 0;
	i = 0;
	while (i < size)
	{
		tmp = stacka;
		while (tmp->next != NULL)
		{
			dptr = tmp->content;
			if (*dptr == nums[i])
			{
				found++;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
	if (found != size)
		return (0);
	return (issorted(stacka));
}
// add sorting algorithm

void	sort(t_list *stacka, t_list *stackb, int *nums, int size)
{
	while (!sorted(stacka, nums, size))
	{
	}
	(void)stackb;
}

void	fill_stacks(t_list *stacka, int *nums, int size)
{
	int		i;
	t_list	*tmpa;

	tmpa = stacka;
	i = 0;
	while (i < size)
	{
		tmpa->content = (nums + i);
		tmpa = tmpa->next;
		i++;
	}
}

void	allocate_stacks(t_list *stacka, t_list *stackb, int size)
{
	t_list	*tmpa;
	t_list	*tmpb;
	int		i;

	i = 0;
	tmpa = stacka;
	tmpb = stackb;
	while (i < size)
	{
		ft_lstadd_back(&tmpa, ft_lstnew(0));
		ft_lstadd_back(&tmpb, ft_lstnew(0));
		i++;
	}
}
