/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapoperations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:35:03 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/09 14:35:22 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrb(t_list *stackb)
{
	t_list	*tmpb;
	t_list	*tmpbblast;
	t_list	*tmplast;

	if (stackb == NULL)
		return ;
	if (stackb->next == NULL)
		return ;
	tmpb = stackb;
	tmplast = ft_lstlast(tmpb);
	while (tmpbblast->next->next != NULL)
		tmpbblast = tmpbblast->next;
	tmpbblast->next = NULL;
	tmplast->next = tmpb;
	stackb = tmplast;
}

void	rrr(t_list *stacka, t_list *stackb)
{
	ra(stacka);
	rb(stackb);
}

void	ra(t_list *stacka)
{
	t_list	*tmpa;
	t_list	*tmpanext;

	tmpa = stacka;
	tmpanext = tmpa->next;
	tmpa->next = NULL;
	ft_lstlast(tmpanext)->next = tmpa;
	stacka = tmpanext;
}

void	rb(t_list *stackb)
{
	t_list	*tmpb;
	t_list	*tmpbnext;

	tmpb = stackb;
	tmpbnext = tmpb->next;
	tmpb->next = NULL;
	ft_lstlast(tmpbnext)->next = tmpb;
	stackb = tmpbnext;
}

void	rr(t_list *stacka, t_list *stackb)
{
	ra(stacka);
	rb(stackb);
}
