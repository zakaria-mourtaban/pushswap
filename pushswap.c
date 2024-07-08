/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:18:55 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/08 11:35:44 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	issorted(t_list *stacka, t_list *stackb, int *nums, int size)
{
	t_list	*tmp;

	tmp = stacka;
	while (tmp->next != NULL)
	{
		if (!(tmp->content < tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	sorted(t_list *stacka, t_list *stackb, int *nums, int size)
{
	t_list	*tmp;
	int		i;
	int		found;

	found = 0;
	i = 0;
	while (i < size)
	{
		tmp = stacka;
		while (tmp->next != NULL)
		{
			if (tmp->content == nums[i])
			{
				found++;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
	if (found != size)
		return (0);
	return (issorted(stacka, stackb, nums, size));
}

void	sort(t_list *stacka, t_list *stackb, int *nums, int size)
{
	while (!sorted(stacka, stackb, nums, size))
	{
	}
	// sorting alg
}

void	fill_stacks(t_list *stacka, int *nums, int size)
{
	int		i;
	t_list	*tmpa;

	tmpa = stacka;
	i = 0;
	
	while (i < size)
	{
		tmpa->content = nums[i];
		tmpa = tmpa->next;
		i++;
	}
}

void	allocate_stacks(t_list *stacka, t_list *stackb, int *nums, int size)
{
	t_list	*tmpa;
	t_list	*tmpb;
	int		i;

	tmpa = stacka;
	tmpb = stackb;
	while (i < size)
	{
		ft_lstadd_back(&tmpa,ft_lstnew(NULL));
		ft_lstadd_back(&tmpb,ft_lstnew(NULL));
		i++;
	}
	
}

void	init_sorting(int *nums, int size)
{
	t_list	*stack[2];

	stack[0] = ft_lstnew(NULL);
	if (stack[0] == NULL)
		return ;
	stack[1] = ft_lstnew(NULL);
	if (stack[1] == NULL)
		return ;
	allocate_stacks(stack[0], stack[1], nums, size);
	sort(stack[0], stack[1], nums, size);
	free_stacks(stack[0], stack[1]);
}

int	main(int ac, char *av[])
{
	char	**variables;
	int		*nums;
	int		arrsize;

	if (ac == 2)
		variables = ft_split(av[1], ' ');
	else
		variables = (av + 1);
	if (!ft_isdigitarr(variables))
		errorandexit("ERRORd");
	if (morethanint(variables))
		errorandexit("ERRORn");
	arrsize = vartoarr(variables, &nums);
	if (arrsize == 0)
		free_variables(variables, nums);
	if (dupinarr(nums, arrsize) && arrsize > 1)
		errorandexit("ERRORdup");
	init_sorting(nums, arrsize);
	free_variables(variables, nums);
	return (0);
}
