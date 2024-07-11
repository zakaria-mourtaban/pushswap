/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaputils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:17:30 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/11 12:40:30 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	issorted(t_list *stacka)
{
	t_list	*tmp;

	tmp = stacka;
	while (tmp->next != NULL)
	{
		if (!(*(int *)(tmp->content) < *(int *)(tmp->next->content)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	sorted(t_list *stacka, int *nums, int size)
{
	t_list	*tmp;
	int		i;
	int		found;

	found = 0;
	i = 0;
	while (i <= size - 1)
	{
		tmp = stacka;
		while (tmp->next != NULL)
		{
			if (*(int *)tmp->content == nums[i])
			{
				found++;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
	if (found != size - 1)
		return (0);
	return (issorted(stacka));
}
// add sorting algorithm

t_list	*getlist(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	return (tmp);
}

void	sort(t_list **stacka, t_list **stackb, int *nums, int size)
{
	while (!sorted(*stacka, nums, size) && getlist(stacka)->next != NULL)
	{
		if (getlist(stacka)->content < getlist(stacka)->next->content)
			sa(stacka);
		rra(stacka);
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
	while (i < size - 1)
	{
		ft_lstadd_back(&tmpa, ft_lstnew(0));
		ft_lstadd_back(&tmpb, ft_lstnew(0));
		i++;
	}
}
