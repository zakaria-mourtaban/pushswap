/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapoperations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:00:06 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/09 15:25:29 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// swap the values not the nodes dumbass
void	sa(t_list *stacka)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (stacka == NULL)
		return ;
	if (stacka->next == NULL)
		return ;
	tmp1 = stacka;
	tmp2 = stacka->next;
	tmp3 = stacka->next->next;
	tmp1->next = tmp3;
	tmp2->next = tmp1;
}

void	sb(t_list *stackb)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (stackb == NULL)
		return ;
	if (stackb->next == NULL)
		return ;
	tmp1 = stackb;
	tmp2 = stackb->next;
	tmp3 = stackb->next->next;
	tmp1->next = tmp3;
	tmp2->next = tmp1;
}

void	ss(t_list *stacka, t_list *stackb)
{
	sa(stacka);
	sb(stackb);
}

void	pa(t_list *stacka, t_list *stackb)
{
	t_list	*tmpb;

	if (stackb == NULL)
		return ;
	if (stacka == NULL)
		return ;
	tmpb = stackb;
	stackb = stackb->next;
	tmpb->next = stacka;
	stacka = tmpb;
}

void	pb(t_list *stacka, t_list *stackb)
{
	t_list	*tmpa;

	if (stackb == NULL)
		return ;
	if (stacka == NULL)
		return ;
	tmpa = stacka;
	stacka = stacka->next;
	tmpa->next = stackb;
	stacka = tmpa;
}
