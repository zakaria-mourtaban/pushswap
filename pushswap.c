/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:18:55 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/10 21:04:57 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_sorting(int *nums, int size, t_list *stacka, t_list *stackb)
{
	stackb = NULL;
	stacka = ft_lstnew(NULL);
	if (stacka == NULL)
		return ;
	allocate_stacks(stacka, stackb, size);
	fill_stacks(stacka, nums, size);
	//sort(stack[0], stack[1], nums, size);
	rra(&stacka);
	printf("\nstack a: ");
	printlist(&stacka);
	// printf("\nstack b: ");
	// printlist(&stackb);
	// printf("\nsorted: %d\n", sorted(stacka, nums, size));
}

int	main(int ac, char *av[])
{
	char	**variables;
	int		*nums;
	int		arrsize;
	t_list	*stackb;
	t_list	*stacka;

	stacka = NULL;
	stackb = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
		variables = ft_split(av[1], ' ');
	else
		variables = (av + 1);
	if ((!ft_isdigitarr(variables)) || morethanint(variables))
		errorandexit("ERROR");
	arrsize = vartoarr(variables, &nums);
	if (arrsize == 0)
		free_variables(variables, nums);
	if (dupinarr(nums, arrsize) && arrsize > 1)
		errorandexit("ERRORdup");
	init_sorting(nums, arrsize, stacka, stackb);
	// make a free function
	return (0);
}
