/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:21:19 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/06 16:40:29 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					dupinarr(int *nums, int size);
int					morethanint(char **vars);
int					ft_isdigitarr(char **s);
int					vartoarr(char **var, int **arr);
long long			ft_atoll(const char *str);
void				free_variables(char **variables, int *single_ptr);
void				errorandexit(char *msg);

#endif