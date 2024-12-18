/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:39:06 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/18 05:29:06 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_helps(t_swap *swap, t_swap *target, t_stack *a, t_stack *b)
{
	if (swap->is_above_median && target->is_above_median)
		rr(a, b);
	else if (!swap->is_above_median && !target->is_above_median)
		rrr(a, b);
	else
	{
		if (swap->is_above_median)
			ra(a);
		else
			rra(a);
		if (target->is_above_median)
			rb(b);
		else
			rrb(b);
	}
}

static void	op_help(t_swap *swap, t_swap *target, t_stack *a, t_stack *b)
{
	if (swap == (t_swap *)a->top->content)
	{
		if (target == (t_swap *)b->top->content)
			return ;
		else if (target->is_above_median)
			rb(b);
		else
			rrb(b);
	}
	else if (target == (t_swap *)b->top->content)
	{
		if (swap == (t_swap *)a->top->content)
			return ;
		else if (swap->is_above_median)
			ra(a);
		else
			rra(a);
	}
	else
		op_helps(swap, target, a, b);
}

void	chpst_swap(t_swap *swp, t_swap **min)
{
	swp->is_cheapest = true;
	(*min)->is_cheapest = false;
	*min = swp;
}

void	op_a(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	t_swap	*tget;
	t_swap	*swp;

	tmp = a->top;
	while (tmp != NULL)
	{
		swp = (t_swap *)tmp->content;
		tget = (t_swap *)swp->target->content;
		if (swp->is_cheapest)
			while (swp != a->top->content || tget != b->top->content)
				op_help(swp, tget, a, b);
		tmp = tmp->next;
	}
	pb(a, b);
}

void	op_b(t_stack *a, t_stack *b)
{
	t_list	*target;
	t_swap	*swp;

	target = ((t_swap *)b->top->content)->target;
	while (a->top != target)
	{
		swp = (t_swap *)target->content;
		if (swp->is_above_median)
			while (a->top->content != swp)
				ra(a);
		else
			while (a->top->content != swp)
				rra(a);
	}
	pa(b, a);
}
