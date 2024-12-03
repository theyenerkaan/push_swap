/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:37:28 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/02 21:39:31 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*transaction_max(t_stack *stack)
{
	t_list	*max;
	t_list	*temp;

	max = stack->top;
	temp = stack->top;
	while (temp != NULL)
	{
		if (swp_cmp(temp->content, max->content))
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_list	*transaction_min(t_stack *stack)
{
	t_list	*min;
	t_list	*temp;

	min = stack->top;
	temp = stack->top;
	while (temp != NULL)
	{
		if (!swp_cmp(temp->content, min->content))
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	transaction_b(t_swap *val, t_stack *a)
{
	t_list	*temp;
	t_swap	*swap;
	t_swap	*target;

	temp = a->top;
	val->target = find_max(a);
	if (val->nbr > ((t_swap *)val->target->content)->nbr)
	{
		val->target = find_min(a);
		return ;
	}
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		target = (t_swap *)val->target->content;
		if (val->nbr < swap->nbr && swap->nbr < target->nbr)
			val->target = temp;
		temp = temp->next;
	}
}

void	transaction_a(t_swap *val, t_stack *b)
{
	t_list	*temp;
	t_swap	*swap;
	t_swap	*target;

	temp = b->top;
	val->target = find_min(b);
	if (val->nbr <= ((t_swap *)val->target->content)->nbr)
	{
		val->target = find_max(b);
		return ;
	}
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		target = (t_swap *)val->target->content;
		if (val->nbr > swap->nbr && swap->nbr > target->nbr)
			val->target = temp;
		temp = temp->next;
	}
}
