/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:44:32 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/01 02:23:45 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t ft_arrlen(char **arr)
{
	size_t i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i] && *arr[i] != '\n')
		i++;
	return (i);
}

void ft_arrfree(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
bool swp_cmp(void *prev, void *next)
{
	return (*(int *)prev < *(int *)next);
}
void swp_print(void *swap)
{
	ft_printf("%d\n", ((t_swap *)swap)->nbr);
}
