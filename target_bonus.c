/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:05:51 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/18 06:45:23 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = ((t_swap *)stack_a->top->content)->nbr;
	b = ((t_swap *)stack_a->top->next->content)->nbr;
	c = ((t_swap *)stack_a->top->next->next->content)->nbr;
	if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > c && b < c)
		ra(stack_a);
	else if (b > a && a > c)
		rra(stack_a);
	else if (b > c && c > a)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (c > a && a > b)
		sa(stack_a);
}
