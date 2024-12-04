/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:05:51 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/04 16:06:59 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_stack *stack)
{
	t_list	*max;
	t_list	*tmp;

	max = stack->top;
	tmp = stack->top;
	while (tmp != NULL)
	{
		if (swp_cmp(tmp->content, max->content))
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
t_list	*find_min(t_stack *stack)
{
	t_list	*min;
	t_list	*tmp;

	min = stack->top;
	tmp = stack->top;
	while (tmp != NULL)
	{
		if (!swp_cmp(tmp->content, min->content))
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
