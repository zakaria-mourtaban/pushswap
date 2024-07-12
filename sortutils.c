/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:25:06 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/12 20:16:45 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



void	fillindex(t_list **stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	
}

t_list	*nodemax(t_list	**stack)
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

t_list	*nodemin(t_list	**stack)
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

void	tinysort(t_list	**stack)
{
	t_list	*maxnode;

	if (ft_lstsize(*stack) > 3)
		return ;
	maxnode = nodemax(stack);
	printf("max:%d",*(int *)maxnode->content);
	if ((*stack) == maxnode)
		ra(stack);
	else if ((*stack)->next == maxnode)
		rra(stack);
	if (*(int *)((*stack)->content) > (*(int *)(*stack)->next->content))
		sa(stack);
}

void	settarget(t_list **stacka, t_list **stackb, int *nums, int size)
{
	t_list	*tmpa;
	t_list	*tmpb;

	nodemintarget(stacka, stackb);
	while (tmpb != NULL)
	{
		tmpa = *stacka;
		tmpb = *stackb;
		while (tmpa != NULL)
		{
			if (tmpa->content > tmpb->content)
				tmpb->target = tmpa->content;
		}
		
	}
	

}