/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transaction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:37:28 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/16 21:57:35 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*transaction_max(t_stack *stack)
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

t_list	*transaction_min(t_stack *stack)
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

void	transaction_b(t_swap *val, t_stack *a)
{
	t_list	*tmp;
	t_swap	*swp;
	t_swap	*transaction;

	tmp = a->top;
	val->target = find_max(a);
	if (val->nbr > ((t_swap *)val->target->content)->nbr)
	{
		val->target = find_min(a);
		return ;
	}
	while (tmp != NULL)
	{
		swp = (t_swap *)tmp->content;
		transaction = (t_swap *)val->target->content;
		if (val->nbr < swp->nbr && swp->nbr < transaction->nbr)
			val->target = tmp;
		tmp = tmp->next;
	}
}

void	transaction_a(t_swap *val, t_stack *b)
{
	t_list	*tmp;
	t_swap	*swp;
	t_swap	*transaction;

	tmp = b->top;
	val->target = find_min(b);
	if (val->nbr <= ((t_swap *)val->target->content)->nbr)
	{
		val->target = find_max(b);
		return ;
	}
	while (tmp != NULL)
	{
		swp = (t_swap *)tmp->content;
		transaction = (t_swap *)val->target->content;
		if (val->nbr > swp->nbr && swp->nbr > transaction->nbr)
			val->target = tmp;
		tmp = tmp->next;
	}
}
