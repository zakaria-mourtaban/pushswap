/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:59:51 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/13 16:23:54 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	absval(int t)
{
	if (t > 0)
		return (t);
	return (t * -1);
}

void	settarget(t_list **stacka, t_list **stackb)
{
	t_list	*tmpa;
	t_list	*tmpb;
	int		diff;

	tmpb = *stackb;
	nodemintarget(stacka, stackb);
	while (tmpb != NULL)
	{
		tmpa = *stacka;
		diff = INT_MAX;
		while (tmpa != NULL)
		{
			if (*(int *)tmpa->content > *(int *)tmpb->content
				&& (*(int *)tmpa->content - *(int *)tmpb->content) < diff)
			{
				tmpb->target = tmpa;
				diff = absval((*(int *)tmpa->content - *(int *)tmpb->content));
			}
			tmpa = tmpa->next;
		}
		if (*(int *)tmpb->content > *(int *)(nodemax(stacka)->content))
			tmpb->target = nodemin(stacka);
		tmpb = tmpb->next;
	}
}

t_list	*getcheapest(t_list *stacka, t_list *stackb)
{
	t_list	*tmpb;
	t_list	*cheapb;
	int		cost;

	cheapb = NULL;
	tmpb = stackb;
	cost = ft_lstsize(stacka) + ft_lstsize(stackb);
	while (tmpb != NULL)
	{
		if (tmpb->cost + tmpb->target->cost < cost)
		{
			cost = tmpb->cost + tmpb->target->cost;
			cheapb = tmpb;
		}
		tmpb = tmpb->next;
	}
	return (cheapb);
}

void	pushcheapest(t_list **stacka, t_list **stackb)
{
	t_list	*cheapa;
	t_list	*cheapb;

	cheapb = getcheapest(*stacka, *stackb);
	if (cheapb == NULL)
		exit (1);
	cheapa = cheapb->target;
	if (cheapa->abovemedian)
	{
		while (cheapa->index > 0)
			ra(stacka);
	}
	else
		while (cheapa->index > 0)
			rra(stacka);
	if (cheapb->abovemedian)
	{
		while (cheapb->index > 0)
			rb(stackb);
	}
	else
		while (cheapb->index > 0)
			rrb(stackb);
	pa(stacka, stackb);
}

void	nodemintarget(t_list **stacka, t_list **stackb)
{
	t_list	*tmpb;

	tmpb = *stackb;
	while (tmpb != NULL)
	{
		tmpb->target = nodemin((stacka));
		tmpb = tmpb->next;
	}
}
