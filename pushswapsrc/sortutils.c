/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:25:06 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/15 01:57:05 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fillindex(t_list **stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

t_list	*nodemax(t_list **stack)
{
	t_list	*max;
	t_list	*tmp;

	max = (*stack);
	tmp = (*stack);
	while (tmp != NULL)
	{
		if (*(int *)max->content < *(int *)tmp->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_list	*nodemin(t_list **stack)
{
	t_list	*max;
	t_list	*tmp;

	max = (*stack);
	tmp = (*stack);
	while (tmp != NULL)
	{
		if (*(int *)max->content > *(int *)tmp->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	tinysort(t_list **stacka, t_list **stackb)
{
	t_list	*maxnode;

	if (ft_lstsize(*stacka) > 3)
		return ;
	maxnode = nodemax(stacka);
	if ((*stacka) == maxnode)
		ra(stacka, stackb);
	else if ((*stacka)->next == maxnode)
		rra(stacka, stackb);
	if (*(int *)((*stacka)->content) > (*(int *)(*stacka)->next->content))
		sa(stacka, stackb);
}

void	cost(t_list **stacka, t_list **stackb)
{
	t_list	*tmpa;
	t_list	*tmpb;

	tmpa = *stacka;
	tmpb = *stackb;
	while (tmpa != NULL)
	{
		tmpa->cost = ft_lstsize(*stacka) - tmpa->index;
		if (tmpa->index < (ft_lstsize(*stacka) / 2))
			tmpa->cost = tmpa->index;
		tmpa = tmpa->next;
	}
	while (tmpb != NULL)
	{
		tmpb->cost = ft_lstsize(*stackb) - tmpb->index;
		if (tmpb->index < ft_lstsize(*stackb) / 2)
			tmpb->cost = tmpb->index;
		tmpb = tmpb->next;
	}
}
// void	settarget(t_list **stacka, t_list **stackb, int *nums, int size)
// {
// 	t_list	*tmpa;
// 	t_list	*tmpb;

// 	nodemintarget(stacka, stackb);
// 	while (tmpb != NULL)
// 	{
// 		tmpa = *stacka;
// 		tmpb = *stackb;
// 		while (tmpa != NULL)
// 		{
// 			if (tmpa->content > tmpb->content)
// 				tmpb->target = tmpa->content;
// 		}
// 	}
// }
