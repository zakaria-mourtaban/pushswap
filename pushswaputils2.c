/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaputils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:50:52 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/09 13:51:45 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	printlist(t_list *node)
{
	t_list	*tmp;
	int		*d;

	tmp = node;
	while (tmp != NULL)
	{
		d = tmp->content;
		if (d != NULL)
			printf("%d ", *d);
		tmp = tmp->next;
	}
}

void	fillstack(t_list *stacka, int *nums, int size)
{
	int		i;
	int		*nptr;
	t_list	*tmp;

	if (stacka == NULL)
		return ;
	tmp = stacka;
	i = 0;
	while (i < size)
	{
		nptr = NULL;
		nptr = malloc(sizeof(int));
		if (nptr == NULL)
			return ;
		*nptr = nums[i];
		tmp->content = nptr;
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}
