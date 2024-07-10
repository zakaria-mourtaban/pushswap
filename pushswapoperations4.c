/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapoperations4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:38:03 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/10 21:05:26 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*get_list_bottom(t_list *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* get_list_before_bottom:
*	Returns the second to last element of the stack.
*/
t_list	*get_list_before_bottom(t_list *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

int	reverserotate(t_list **stack)
{
	//t_list	*head;
	t_list	*beforelast;
	t_list	*tail;

	//head = *stack;
	tail = ft_lstlast(*stack);
	beforelast = *stack;
	while (beforelast->next->next->next != NULL)
		beforelast = beforelast->next;
	beforelast->next = NULL;
	//tail->next = head;
	*stack = tail;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverserotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverserotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverserotate(stack_a);
	reverserotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
