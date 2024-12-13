/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:44:32 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/13 01:18:18 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_arrlen(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i] && *arr[i] != '\n')
		i++;
	return (i);
}

void	ft_arrfree(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

bool	swp_cmp(void *curr, void *next)
{
	return (((t_swap *)curr)->nbr > ((t_swap *)next)->nbr);
}

void	swp_print(void *swap)
{
	ft_printf("%d\n", ((t_swap *)swap)->nbr);
}