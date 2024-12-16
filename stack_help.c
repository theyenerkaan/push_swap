/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:30:14 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/16 17:47:35 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_sort(t_stack *stack) {
	t_list	*big;

	big = find_max(stack);
	if (big == stack->top)
		ra(stack);
	else if (big == stack->top->next)
		rra(stack);
	if (!ft_lstsort(stack->top, swp_cmp))
		sa(stack);
}

void	prepare_or(t_stack *stack) {
	t_list	*temp;
	t_swap	*swap;
	int		i;

	i = 0;
	temp = stack->top;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		swap->index = i++;
		swap->is_cheapest = false;
		if (swap->index <= stack->count / 2)
			swap->is_above_median = true;
		else
			swap->is_above_median = false;
		temp = temp->next;
	}
}

void	load_stack(t_stack *find, t_stack *target,
				void (*prcs)(t_swap *value, t_stack *target))
{	
	t_list	*tmp;
	t_swap	*swp;

	tmp = find->top;
	prepare_or(find);
	prepare_or(target);
	while (tmp != NULL)
	{
		swp = (t_swap *)tmp->content;
		prcs(swp, target);
		tmp = tmp->next;
	}
}

static void	cheapest(t_stack *find, t_stack *target) {
	t_swap	*swp;
	t_swap	*tget;
	t_list	*tmp;
	t_swap	*min;

	tmp = find->top;
	min = (t_swap *)tmp->content;
	min->is_cheapest = true;
	while (tmp != NULL)
	{
		swp = (t_swap *)tmp->content;
		tget = (t_swap *)swp->target->content;
		if (swp->is_above_median)
			swp->cost = swp->index;
		else
			swp->cost = find->count - swp->index;
		if (tget->is_above_median)
			swp->cost += tget->index;
		else
			swp->cost += target->count - tget->index;
		swp->cost++;
		if (swp->cost < min->cost)
			chpst_swap(swp, &min);
		tmp = tmp->next;
	}
}

void	sorting(t_stack *a, t_stack *b) {
	t_list	*min;

	while (a->count > 3)
	{
		load_stack(a, b, transaction_a);
		cheapest(a, b);
		op_a(a, b);
	}
	if (!ft_lstsort(a->top, swp_cmp))
		the_sort(a);
	while (b->count > 0)
	{
		load_stack(b, a, transaction_b);
		op_b(a, b);
	}
	prepare_or(a);
	min = find_min(a);
	while (a->top != min)
	{
		if (((t_swap *)min->content)->is_above_median)
			ra(a);
		else
			rra(a);
	}
}
