/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapoperations3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:35:48 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/09 14:36:03 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_list *stacka)
{
	t_list	*tmpa;
	t_list	*tmpablast;
	t_list	*tmplast;

	if (stacka == NULL)
		return ;
	if (stacka->next == NULL)
		return ;
	tmpa = stacka;
	tmplast = ft_lstlast(tmpa);
	while (tmpablast->next->next != NULL)
		tmpablast = tmpablast->next;
	tmpablast->next = NULL;
	tmplast->next = tmpa;
	stacka = tmplast;
}
