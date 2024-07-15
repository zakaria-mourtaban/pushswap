/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaputils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:17:30 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/15 03:27:07 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort(t_list **stacka, t_list **stackb, int *nums, int size)
{
	while (ft_lstsize(*stacka) > 3)
		pb(stacka, stackb);
	tinysort(stacka, stackb);
	while (!sorted(*stacka, nums, size) && *stackb != NULL )
	{
		settarget(stacka, stackb);
		cost(stacka, stackb);
		pushcheapest(stacka, stackb);
		// printlist(stacka);
	}
	while (!sorted(*stacka, nums, size))
		rra(stacka, stackb);
}

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

void	fill_stacks(t_list *stacka, int *nums, int size)
{
	int		i;
	t_list	*tmpa;

	tmpa = stacka;
	i = 0;
	while (i < size)
	{
		tmpa->content = (nums + i);
		tmpa->index = i;
		tmpa->target = NULL;
		tmpa = tmpa->next;
		i++;
	}
}

void	allocate_stacks(t_list *stacka, int size)
{
	t_list	*tmpa;
	int		i;

	i = 0;
	tmpa = stacka;
	while (i < size - 1)
	{
		ft_lstadd_back(&tmpa, ft_lstnew(0));
		i++;
	}
}
