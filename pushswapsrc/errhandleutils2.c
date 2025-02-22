/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errhandleutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:45:02 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/15 02:51:08 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	errorandexit(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

void	free_variables(char **variables, int *single_ptr, int bol)
{
	int	i;

	i = 0;
	if (single_ptr != NULL)
		free(single_ptr);
	if (variables == NULL)
		return ;
	while (variables[i] != NULL)
	{
		free(variables[i++]);
		i++;
	}
	free(variables);
	if (bol == 1)
		errorandexit("ERROR");
}

int	morethanint(char **vars)
{
	int				i;
	long long int	num;

	i = 0;
	while (vars[i] != NULL)
	{
		if (ft_strlen(vars[i]) > 10)
			return (1);
		num = ft_atoll(vars[i]);
		if (num > (long)INT_MAX || num < (long)INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigitarr(char **s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[j] != NULL)
	{
		i = 0;
		while (s[j][i] != '\0')
		{
			if ((!(s[j][i] >= '0' && s[j][i] <= '9')) && s[j][i] != '-'
				&& s[j][i] != '+')
				return (0);
			i++;
		}
		if ((s[j][0] == '-' && s[j][1] == '\0') || (s[j][0] == '+'
				&& s[j][1] == '\0'))
			return (0);
		j++;
	}
	return (1);
}
