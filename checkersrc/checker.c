/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 02:14:29 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/15 03:47:35 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checksorted(t_list *stacka, t_list *stackb, int *nums, int size)
{
	char	*line;

	line = ft_get_next_line(0);
	while (line[0] != '\0')
	{
		if (ft_strncmp(line,"ra",2))
			ra(&stacka,&stackb);
		if (ft_strncmp(line,"rra",2))
			ra(&stacka,&stackb);
		if (ft_strncmp(line,"rb",2))
			rb(&stacka,&stackb);
		if (ft_strncmp(line,"rrb",2))
			rrb(&stacka,&stackb);
		if (ft_strncmp(line,"sa",2))
			sa(&stacka,&stackb);
		if (ft_strncmp(line,"sb",2))
			sb(&stacka,&stackb);
		if (ft_strncmp(line,"ss",2))
			ss(&stacka,&stackb);
		if (ft_strncmp(line,"pa",2))
			pa(&stacka,&stackb);
		if (ft_strncmp(line,"pb",2))
			pb(&stacka,&stackb);
	}
	if (sorted(stacka,nums,size))
		ft_printf("OK");
	else
		ft_printf("KO");
	return ;
}

int	main(int ac, char **av)
{
	char	**variables;
	int		*nums;
	int		arrsize;
	t_list	*stackb;
	t_list	*stacka;

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
		free_variables(variables, nums, 1);
	if (dupinarr(nums, arrsize) && arrsize > 1)
		errorandexit("ERROR");
	stackb = NULL;
	stacka = ft_lstnew(NULL);
	if (stacka == NULL)
		exit(1);
	allocate_stacks(stacka, arrsize);
	fill_stacks(stacka, nums, arrsize);
	checksorted(stacka, stackb,nums,arrsize);
	ft_free(&stacka);
	ft_free(&stackb);
	free(nums);
	return (0);
}